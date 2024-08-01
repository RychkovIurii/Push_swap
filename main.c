/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/01 17:50:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void print_ab(t_stack *a, t_stack *b) {
	t_stack *temp_a = a;
	t_stack *temp_b = b;

	ft_printf("Stack A:\n");
	while (temp_a) {
		ft_printf("%d\n", temp_a->data);
		temp_a = temp_a->next;
	}

	ft_printf("\nStack B:\n");
	while (temp_b) {
		ft_printf("%d\n", temp_b->data);
		temp_b = temp_b->next;
	}

	if (is_sorted(a))
		ft_printf("\nStack A is sorted\n");
	else
		ft_printf("\nStack A is not sorted\n");
} */

int main(int ac, char *av[])
{
	int	stacksize;
	int		flag;
	t_stack	*a;
	t_stack	*b;
	char	**set;

	a = NULL;
	b = NULL;
	set = NULL;
	flag = 0;
	stacksize = 0;
	if (ac == 1)
		return (1);
	else if (ac != 2)
		a = init_stack((av + 1), flag);
	else
	{
		flag = 1;
		set = ft_split(av[1], ' ');
		if (!set)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		a = init_stack(set, flag);
		free_set(set);
	}
	stacksize = stack_size(a);
	if (stacksize == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else if (stacksize == 2 && !(is_sorted(a)))
		sa(&a);
	else if (stacksize == 3)
		sort_three(&a);
	else if (stacksize > 3)
	{
		while (stack_size(a) > 3 && !(is_sorted(a)))
			pb(&a ,&b);
		sort_three(&a);
		while (b)
		{
			init_info(a, b);
			fill_a(&a, &b);
		}
 		sort_almost_sorted(&a);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
