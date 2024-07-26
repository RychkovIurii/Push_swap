/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:00:33 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/26 10:17:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (*stack == NULL || (*stack)->next == NULL)
	return;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("\t\tsa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("\t\tsb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("\t\tss\n");
}
