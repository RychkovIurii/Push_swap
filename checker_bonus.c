/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:02:01 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/05 14:16:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		split_args = concat_and_split_args(ac, av);
		if (!split_args)
			print_and_exit();
		a = init_stack(split_args);
		free_set(split_args);
	}
	else
		return (0);
	read_and_execute_instructions(&a, &b);
	if (is_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
