/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:12:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/26 10:19:04 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack *prev;
	t_stack *current;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("\t\trra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("\t\trrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("\t\trrr\n");
}
