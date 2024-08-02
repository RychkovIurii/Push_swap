/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 16:15:42 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		a = handle_single_argument(av[1]);
	else
		a = init_stack((av + 1), 0);
	sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
