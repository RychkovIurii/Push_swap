/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/19 10:55:43 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		++i;
	}
	free(set);
}

t_stack	*init_stack(char **set)
{
	int	i;
	t_stack *cursor;
	t_stack	*new;
	t_stack	*a;

	i = 0;
	a = NULL;
	cursor = NULL;
	while (set[i])
	{
		new = malloc (sizeof(*new));
		if (!new)
		{
			free_set(set);
			free_stack(a);
			exit(1);
		}
		new->data = ft_atoi(set[i]);
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
	int i;
	t_stack *a;
	t_stack *b;
	char    **set;

	i = 0;
	a = NULL;
	b = NULL;
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
	}
	b = a;
	while (b)
	{
		ft_printf("%d\n", b->data);
		b = b->next;
	}
	free_set(set);
	free_stack(a);
	return 0;
}
/* In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */
