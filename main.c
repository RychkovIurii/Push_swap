/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/26 10:20:59 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	int		resets;
	t_stack	*current;

	if (!stack || !stack->next)
		return 1; //Error check?

	current = stack;
	resets = 0;
	while (current->next)
	{
		if (current->data > current->next->data)
			resets++;
		current = current->next;
	}
	if (stack->data < current->data)
		resets++;
	return resets <= 1;
}

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
	if(!check_isdigit(set))
	{
		ft_printf("Error\n");
		if (flag)
			free_set(set);
		exit(1);
	}
	while (set[i])
	{
		new = malloc (sizeof(*new));
		if (!new)
		{
			if (flag)
				free_set(set);
			free_stack(a);
			exit(1);
		}
		if (!ft_atoi2(set[i], &num) || !check_duplicates(a, num))
		{
			ft_printf("Error\n");
			free(new);
			if (flag)
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

void print_ab(t_stack *a, t_stack *b) {
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
}

int main(int ac, char *av[])
{
	int		flag;
	t_stack	*a;
	t_stack	*b;
	char	**set;

	a = NULL;
	b = NULL;
	set = NULL;
	flag = 0;
	if (ac == 1)
		return (1);
	//validation for several args and isdigit, modify atoi to handle(0, -1)
	else if (ac != 2)
		a = init_stack((av + 1), flag);
	else
	{
		flag = 1;
		set = ft_split(av[1], ' ');
		if (!set)
			return (1);
		a = init_stack(set, flag);
		free_set(set);
	}
	pb(&a ,&b);
	pb(&a ,&b);
	pb(&a ,&b);
	pb(&a ,&b);
	pb(&a ,&b);
	print_ab(a, b);

	pa(&a ,&b);
	print_ab(a, b);

	sa(&a);
	print_ab(a, b);

	sb(&b);
	print_ab(a, b);

	ss(&a, &b);
	print_ab(a, b);

	ra(&a);
	print_ab(a, b);

	rb(&b);
	print_ab(a, b);

	rr(&a, &b);
	print_ab(a, b);

	rra(&a);
	print_ab(a, b);

	rrb(&b);
	print_ab(a, b);

	rrr(&a, &b);
	print_ab(a, b);
	
	return (0);
}
/* In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */
