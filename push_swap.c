/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:28:26 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/18 18:16:09 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void);

/* I use a special kind of atoi, therefore I'll implement
 * my_atoi function which will handle some error cases.
 */
int	my_atoi(char *args)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_args(args))
		print_error();
	i = 0;
	sign = 1;
	value = 0;
	if (args[i] == '+' || args[i] == '-')
	{
		if (args[i++] == '-')
			sign = -1;
	}
	while (args[i])
		value = value * 10 + (args[i++] - '0');
	value = value * sign;
	if (value > MAX_INT || value < MAX_INT)
		print_error();
	return (value);
}

// A standard error message.
void	print_error(void)
{
	ft_putendl_fd("Error\n", 2);
}

// ######################################################
// ############A function to free the stacks.############
// ######################################################
static void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node)
	{
		if (node->next)
			tmp = node->next;
		else
			tmp = NULL;
		free(node);
		if (tmp)
			node = tmp;
		else
			break;
	}
	free(stack);
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

// #######################################################

/*
 * Check if stack a is sorted or not yet.
 */
int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}


// ############# Initialize the values ##############
void	init_values(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}


// ################ above five ######################
static int	exception(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		under_three_handler(r, a, b, A);
		return (0);
	}
	else if (r == 5)
	{
		sort_five_handler(5, a, b, A);
		return (0);
	}
}

void	a_to_b(int r, t_stack *a, t_stack *b, int *count)
{
	int		tmp;
	t_value	var;

	if (!exceptions(r, a, b))
		return ;
	init_values(&var);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	if (a->size == 5)
		five_handler(a, b);
	else
		a_to_b(a->size, a, b, &count);
}

/*
 * Declare the stacks and take the arguments,
 * if no argument is given return an error message.
 * while there is an argument left init the stack a,
 * and fill it with the arguments.
 */


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	i = 0;
	if (argc > 1)
	{
		a = init_stack();
		a->top = fill_stack(argc, argv, &a);
		b = init_stack();
		if (is_sorted(a))
		{
			free_all(a, b);
			return (0);
		}
		push_swap(a, b);
		free_all(a, b);
	}
}
