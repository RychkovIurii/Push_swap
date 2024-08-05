/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:11:25 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/05 14:12:31 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*concat_args(char *combined, char *arg)
{
	char	*temp;

	temp = ft_strjoin(combined, arg);
	if (!temp)
		print_and_free(combined);
	free(combined);
	combined = ft_strjoin(temp, " ");
	if (!combined)
		print_and_free(temp);
	free(temp);
	return (combined);
}

char	**concat_and_split_args(int ac, char *av[])
{
	int		i;
	char	*combined;
	char	**split_args;

	i = 2;
	if (av[1][0] == '\0')
		print_and_exit();
	combined = ft_strjoin(av[1], " ");
	if (!combined)
		print_and_exit();
	while (i < ac)
	{
		if (av[i][0] == '\0')
			print_and_free(combined);
		combined = concat_args(combined, av[i]);
		i++;
	}
	split_args = ft_split(combined, ' ');
	free(combined);
	return (split_args);
}
