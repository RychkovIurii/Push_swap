/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/19 14:30:30 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	long long int	check;
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

int	check_digit(char **set)
{
	int	i;
	int	j;

	i = 0;
	while (set[i])
	{
		//Think how to handle '-' and '+'
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

void	free_stack(t_stack *a)
{
	t_stack *cursor;

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

t_stack	*init_stack(char **set)
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
	if(!check_digit(set))
	{
		ft_printf("Error\n");
		free_set(set);
		exit(1);
	}
	while (set[i])
	{
		new = malloc (sizeof(*new));
		if (!new)
		{
			ft_printf("Error\n");
			free_set(set);
			free_stack(a);
			exit(1);
		}
		if (!ft_atoi2(set[i], &num))
		{
			free_set(set);
			free_stack(a);
			exit(1);
		}
		new->data = num;
		new->next = NULL;
		if (a == NULL) // First element
			a = new;
		else
			cursor->next = new;
		cursor = new;
		i++;
	}
	return (a);

}

int main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	char    **set;

	a = NULL;
	b = NULL;
	set = NULL;
	if (ac == 1)
		return (1);
	//validation for several args and isdigit, modify atoi to handle(0, -1)
	else if (ac != 2)
		a = init_stack(av + 1);
	else
	{
		set = ft_split(av[1], ' ');
		if (!set)
			return (1);
		a = init_stack(set);
		free_set(set);
	}
	b = a;
	while (b)
	{
		ft_printf("%d\n", b->data);
		b = b->next;
	}
	free_stack(a);
	return 0;
}
/* In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */
