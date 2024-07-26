/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:08:57 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/26 10:17:42 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack *temp;

	if (*src == NULL)
		return;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("\t\tpa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("\t\tpb\n");
}
