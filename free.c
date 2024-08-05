/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:42:41 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/05 13:47:54 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_stack	*cursor;

	while (a)
	{
		cursor = a->next;
		free(a);
		a = cursor;
	}
}

void	free_set(char **set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		free(set[i]);
		i++;
	}
	free(set);
}

void	print_and_free(char *str)
{
	free(str);
	print_and_exit();
}

void	print_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	handle_error(char **set, t_stack *stack)
{
	free_set(set);
	free_stack(stack);
	print_and_exit();
}
