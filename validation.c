/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:23 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/05 13:48:42 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(t_stack *a, int num)
{
	while (a)
	{
		if (a->data == num)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	check_isdigit(char **set)
{
	int	i;
	int	j;

	i = 0;
	while (set[i])
	{
		j = 0;
		if (set[i][j] == '-' || set[i][j] == '+')
			j++;
		if (set[i][j] == '\0')
			return (0);
		while (set[i][j])
		{
			if (!ft_isdigit(set[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	validate_input(char **set)
{
	if (!check_isdigit(set))
	{
		free_set(set);
		print_and_exit();
	}
}

static t_stack	*create_new_element(char *str, t_stack *stack, char **set)
{
	t_stack	*new;
	int		num;

	num = 0;
	new = malloc(sizeof(*new));
	if (!new)
		handle_error(set, stack);
	if (!ft_atoi2(str, &num) || !check_duplicates(stack, num))
	{
		free(new);
		handle_error(set, stack);
	}
	new->data = num;
	new->next = NULL;
	return (new);
}

t_stack	*init_stack(char **set)
{
	int		i;
	t_stack	*cursor;
	t_stack	*new;
	t_stack	*a;

	i = 0;
	a = NULL;
	cursor = NULL;
	validate_input(set);
	while (set[i])
	{
		new = create_new_element(set[i], a, set);
		if (a == NULL)
			a = new;
		else
			cursor->next = new;
		cursor = new;
		i++;
	}
	return (a);
}
