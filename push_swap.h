/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:13:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/05 14:12:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				above_median;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

void	pa(t_stack **stack_a, t_stack **stack_b, int flag);
void	pb(t_stack **stack_a, t_stack **stack_b, int flag);
void	sa(t_stack **stack_a, int flag);
void	sb(t_stack **stack_b, int flag);
void	ss(t_stack **stack_a, t_stack **stack_b, int flag);
void	ra(t_stack **stack_a, int flag);
void	rb(t_stack **stack_b, int flag);
void	rr(t_stack **stack_a, t_stack **stack_b, int flag);
void	rra(t_stack **stack_a, int flag);
void	rrb(t_stack **stack_b, int flag);
void	rrr(t_stack **stack_a, t_stack **stack_b, int flag);
void	init_info(t_stack *a, t_stack *b);
void	set_index(t_stack *stack);
void	fill_a(t_stack **a, t_stack **b);
void	rotate_to_top(t_stack **stack, t_stack *aim, char stack_name);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_atoi2(const char *str, int *num);
void	sort_almost_sorted(t_stack **a);
void	sort_three(t_stack **stack);
void	free_stack(t_stack *a);
void	free_set(char **set);
void	print_and_free(char *str);
void	print_and_exit(void);
void	handle_error(char **set, t_stack *stack);
char	**concat_and_split_args(int ac, char *av[]);
t_stack	*init_stack(char **set);
t_stack	*get_min(t_stack *stack);

#endif