/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:22:21 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/31 11:53:52 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*ptr;

	ptr = stack;
	i = 0;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

t_stack	*get_cheap(t_stack *stack)
{
	int		min;
	t_stack	*cheap;

	if (!stack)
		return (NULL);
	min = stack->cost;
	cheap = stack;
	while (stack)
	{
		if (stack->cost < min)
		{
			min = stack->cost;
			cheap = stack;
		}
		stack = stack->next;
	}
	return (cheap);
}

void	rotate_to_top(t_stack **stack, t_stack *aim, char stack_name)
{
	while (*stack != aim)
	{
		if (stack_name == 'a')
		{
			if (aim->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (aim->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	fill_a(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheap(*b);
	while (*a != cheap->target && *b != cheap)
	{
		if (cheap->above_median && cheap->target->above_median)
			rr(a, b);
		else if (!(cheap->above_median) && !(cheap->target->above_median))
			rrr(a, b);
		else
			break;
	}
	set_index(*a);
	set_index(*b);
	rotate_to_top(b, cheap, 'b');
	rotate_to_top(a, cheap->target, 'a');
	pa(a, b);
}

t_stack	*get_min(t_stack *stack)
{
	int		minimum;
	t_stack	*min;

	if (!stack)
		return (NULL);
	minimum = stack->data;
	while (stack)
	{
		if (stack->data <= minimum)
		{
			minimum = stack->data;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack *ptr;
	t_stack *target;
	long long int	match;

	while(b)
	{
		match = LONG_MAX;
		ptr = a;
		while(ptr)
		{
			if (ptr->data > b->data && ptr->data < match)
			{
				match = ptr->data;
				target = ptr;
			}
			ptr = ptr->next;
		}
		if (match == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_median))
			b->cost = len_b - (b->index);
		if (b->target->above_median)
			b->cost = b->cost + b->target->index;
		else
			b->cost = b->cost + len_a - (b->target->index);
		b = b->next;
	}
}

void	init_info(t_stack *a, t_stack *b)
{
	set_target(a, b);
	set_index(a);
	set_index(b);
	set_cost(a, b);
}

void sort_three(t_stack **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
		sa(stack), rra(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
		sa(stack), ra(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
}

/* int is_almost_sorted(t_stack *stack)
{
	int		resets;
	t_stack	*current;

	if (!stack || !stack->next)
		return 0; //Error check?

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
	return resets == 2;
} */

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
		ft_putstr_fd("Error\n", 2);
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
			ft_putstr_fd("Error\n", 2);
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

int is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return 0;
		stack = stack->next;
	}
	return 1;
}

void	sort_almost_sorted(t_stack **a)
{
	t_stack *min_node = get_min(*a);
	rotate_to_top(a, min_node, 'a');

	while (!is_sorted(*a))
	{
		if ((*a)->data > (*a)->next->data)
			sa(a);
		else
			ra(a);
	}
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
			return (1);
		a = init_stack(set, flag);
		free_set(set);
	}
	stacksize = stack_size(a);
	/* ft_printf("\nStacksize is %d\n", stacksize); */
	if (stacksize == 2)
		sa(&a);
	else if (stacksize == 3)
		sort_three(&a);
/* 	else if (is_almost_sorted(a))
		sort_almost_sorted(&a); */
	else
	{
		while (stack_size(a) > 3 && !(is_sorted(a)))
			pb(&a ,&b);
		sort_three(&a);
		/* ft_printf("\nStacksize is %d\n", stack_size(a));
		ft_printf("\nStacksize is %d\n", stack_size(b)); */
		
		while (b)
		{
			init_info(a, b);
			fill_a(&a, &b);
			/* ft_printf("\nStacksize A is %d\n", stack_size(a)); */
		}
 		sort_almost_sorted(&a);
	}
	/* print_ab(a, b); */
	free_stack(a);
	free_stack(b);

/* 	pb(&a ,&b);
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
	print_ab(a, b); */
	
	return (0);
}
/* In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */

// ./push_swap "" Should I print Error?