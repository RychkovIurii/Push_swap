/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:30:14 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:14:46 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_cheap(t_stack *stack)
{
	int		min;
	t_stack	*cheap;

	min = stack->cost;
	cheap = stack;
	while (stack)
	{
		if (stack->cost < min)
		{
			min = stack->cost;
			cheap = stack;
		}
		stack = stack->next;
	}
	return (cheap);
}

void	rotate_to_top(t_stack **stack, t_stack *aim, char stack_name)
{
	while (*stack != aim)
	{
		if (stack_name == 'a')
		{
			if (aim->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (aim->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	fill_a(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheap(*b);
	while (*a != cheap->target && *b != cheap)
	{
		if (cheap->above_median && cheap->target->above_median)
			rr(a, b, 1);
		else if (!(cheap->above_median) && !(cheap->target->above_median))
			rrr(a, b, 1);
		else
			break ;
	}
	set_index(*a);
	set_index(*b);
	rotate_to_top(b, cheap, 'b');
	rotate_to_top(a, cheap->target, 'a');
	pa(a, b, 1);
}
