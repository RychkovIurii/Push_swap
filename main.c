/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/18 15:54:34 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_set(void **set, t_stack *a)
{
	int	i;
	t_stack *cursor;

	i = 0;
	while (set[i])
	{
		free(set[i]);
		++i;
	}
	free(set);
	while (a)
	{
		cursor = a->next;
		free(a);
		a = cursor;
	}
}

//init_stack(char **str)

int main(int ac, char *av[])
{
	int i;
	t_stack *cursor;
	t_stack *a;
	t_stack *b;
	char    **set;

	i = 0;
	b = NULL;
	if (ac == 1)
		return (1);
	//validation for several args and isdigit, modify atoi to handle(0, -1)
	set = ft_split(av[1], ' ');

/// init_stack(argv + 1)
	while (set[i] != '\0')
	{
		a = malloc (sizeof(*a));
		if (!a)
			free_set(set, a);
		a->data = ft_atoi(set[i]);
		a->next = NULL;
		cursor = a->next;
		a->next = cursor;
	}

	i = 0;
	while (set[i])
		ft_printf("%s", set[i++]);
	return 0;
}
/* In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */
