/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:35 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 15:37:55 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	execute_instruction(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_strncmp(instruction, "sa\n", 5) == 0)
		sa(a);
	else if (ft_strncmp(instruction, "sb\n", 5) == 0)
		sb(b);
	else if (ft_strncmp(instruction, "ss\n", 5) == 0)
		ss(a, b);
	else if (ft_strncmp(instruction, "pa\n", 5) == 0)
		pa(a, b);
	else if (ft_strncmp(instruction, "pb\n", 5) == 0)
		pb(a, b);
	else if (ft_strncmp(instruction, "ra\n", 5) == 0)
		ra(a);
	else if (ft_strncmp(instruction, "rb\n", 5) == 0)
		rb(b);
	else if (ft_strncmp(instruction, "rr\n", 5) == 0)
		rr(a, b);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		rra(a);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		rrb(b);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		rrr(a, b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	read_and_execute_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		execute_instruction(line, a, b);
		free(line);
	}
}
