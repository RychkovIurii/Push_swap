/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:00:33 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:06:32 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a, int flag)
{
	swap(stack_a);
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int flag)
{
	swap(stack_b);
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	swap(stack_a);
	swap(stack_b);
	if (flag)
		ft_printf("ss\n");
}
