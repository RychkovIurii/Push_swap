/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:36:23 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 11:21:47 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *a, int num)
{
	while (a)
	{
		if (a->data == num)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	ft_helper_atoi2(const char *str, int *sign)
{
	int	index;

	index = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			*sign = -1;
		index++;
	}
	return (index);
}

int	ft_atoi2(const char *str, int *num)
{
	long long int	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = ft_helper_atoi2(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + sign * (str[i] - '0');
		i++;
		if ((result < INT_MIN) || (result > INT_MAX))
			return (0);
	}
	*num = result;
	return (1);
}

int	check_isdigit(char **set)
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
		while(set[i][j])
		{
			if (!ft_isdigit(set[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void validate_input(char **set, int flag)
{
	if(!check_isdigit(set))
	{
		ft_putstr_fd("Error\n", 2);
		if (flag)
			free_set(set);
		exit(1);
	}
}

t_stack	*init_stack(char **set, int flag)
{
	int	i;
	int num;
	t_stack *cursor;
	t_stack	*new;
	t_stack	*a;

	i = 0;
	num = 0;
	a = NULL;
	cursor = NULL;
	validate_input(set, flag);
	while (set[i])
	{
		new = malloc (sizeof(*new));
		if (!new)
			handle_error(set, a, flag);
		if (!ft_atoi2(set[i], &num) || !check_duplicates(a, num))
		{
			free(new);
			handle_error(set, a, flag);
		}
		new->data = num;
		new->next = NULL;
		if (a == NULL)
			a = new;
		else
			cursor->next = new;
		cursor = new;
		i++;
	}
	return (a);
}
