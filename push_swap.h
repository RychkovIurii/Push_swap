/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:13:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/08/02 11:58:40 by irychkov         ###   ########.fr       */
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

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	init_info(t_stack *a, t_stack *b);
void	set_index(t_stack *stack);
void	fill_a(t_stack **a, t_stack **b);
void	rotate_to_top(t_stack **stack, t_stack *aim, char stack_name);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sort_almost_sorted(t_stack **a);
void	sort_three(t_stack **stack);
void	free_stack(t_stack *a);
void	free_set(char **set);
void	handle_error(char **set, t_stack *stack, int flag);
t_stack	*init_stack(char **set, int flag);
t_stack	*get_min(t_stack *stack);

#endif