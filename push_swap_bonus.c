/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:01:35 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:42:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	execute_instruction(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_strncmp(instruction, "sa\n", 5) == 0)
		sa(a, 0);
	else if (ft_strncmp(instruction, "sb\n", 5) == 0)
		sb(b, 0);
	else if (ft_strncmp(instruction, "ss\n", 5) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(instruction, "pa\n", 5) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(instruction, "pb\n", 5) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(instruction, "ra\n", 5) == 0)
		ra(a, 0);
	else if (ft_strncmp(instruction, "rb\n", 5) == 0)
		rb(b, 0);
	else if (ft_strncmp(instruction, "rr\n", 5) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		rra(a, 0);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		rrb(b, 0);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	read_and_execute_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!execute_instruction(line, a, b))
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			free_stack(*a);
			free_stack(*b);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}
