/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:02:01 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:40:03 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_stack	*handle_single_argument(char *av)
{
	t_stack	*a;
	char	**set;

	set = ft_split(av, ' ');
	if (!set)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	a = init_stack(set, 1);
	free_set(set);
	return (a);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		a = handle_single_argument(av[1]);
	else
		a = init_stack((av + 1), 0);
	read_and_execute_instructions(&a, &b);
	if (is_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
