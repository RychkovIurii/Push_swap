/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:12:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:05:54 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
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

void	rra(t_stack **stack_a, int flag)
{
	reverse_rotate(stack_a);
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int flag)
{
	reverse_rotate(stack_b);
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (flag)
		ft_printf("rrr\n");
}
