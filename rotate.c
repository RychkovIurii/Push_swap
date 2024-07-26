/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:10:54 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/26 10:18:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("\t\tra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("\t\trb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("\t\trr\n");
}
