/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:20:59 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/01 17:28:52 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*ptr;

	ptr = stack;
	i = 0;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack *ptr;
	t_stack *target;
	long long int	match;

	while(b)
	{
		match = LONG_MAX;
		ptr = a;
		while(ptr)
		{
			if (ptr->data > b->data && ptr->data < match)
			{
				match = ptr->data;
				target = ptr;
			}
			ptr = ptr->next;
		}
		if (match == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	set_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_median))
			b->cost = len_b - (b->index);
		if (b->target->above_median)
			b->cost = b->cost + b->target->index;
		else
			b->cost = b->cost + len_a - (b->target->index);
		b = b->next;
	}
}

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	init_info(t_stack *a, t_stack *b)
{
	set_target(a, b);
	set_index(a);
	set_index(b);
	set_cost(a, b);
}
