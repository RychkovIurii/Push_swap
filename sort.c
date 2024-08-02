/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:33:25 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:16:25 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min(t_stack *stack)
{
	int		minimum;
	t_stack	*min;

	minimum = stack->data;
	min = stack;
	while (stack)
	{
		if (stack->data <= minimum)
		{
			minimum = stack->data;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack, 1);
	else if (a > b && b > c)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_almost_sorted(t_stack **a)
{
	t_stack	*min_node;

	min_node = get_min(*a);
	rotate_to_top(a, min_node, 'a');
	while (!is_sorted(*a))
	{
		if ((*a)->data > (*a)->next->data)
			sa(a, 1);
		else
			ra(a, 1);
	}
}
