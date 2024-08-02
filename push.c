/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:08:57 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:08:59 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_b, stack_a);
	if (flag)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag)
		ft_printf("pb\n");
}
