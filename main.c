/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/05 14:21:19 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b)
{
	int	stacksize;

	stacksize = stack_size(*a);
	if (stacksize == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (stacksize == 2 && !is_sorted(*a))
		sa(a, 1);
	else if (stacksize == 3)
		sort_three(a);
	else if (stacksize > 3)
	{
		while (stack_size(*a) > 3 && !is_sorted(*a))
			pb(a, b, 1);
		sort_three(a);
		while (*b)
		{
			init_info(*a, *b);
			fill_a(a, b);
		}
		sort_almost_sorted(a);
	}
}

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
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		a = init_stack(split_args);
		free_set(split_args);
	}
	else
		return (0);
	sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
