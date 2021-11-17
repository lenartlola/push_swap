/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:28:26 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/17 13:55:15 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void);

//*************************Argument checks****************************
static int	check_args_length(char *args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (args[0] == '+' || args[0] == '-')
	{
		i++;
		len--;
	}
	while (args[i] == '0')
		i++;
	while (args[i++])
		len++;
	return (len);
}

// Check if the arguments content only digits
static int	is_numeric(char *arg)
{
	int	i;
	if (!arg)
		return (0);
	i = -1;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while(arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

// Check if the arguments are numbers, and the length of digits
// should not be bigger than 11, as well as not smaller than 0.
int	check_args(char *args)
{
	int	len;

	len = check_args_length(args);
	if (!is_numeric(args) || len > 11 || len < 0)
		return (0);
	else
		return (1);
}

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

/*
 * Allocate the memory to the stack
 */

t_stack	*init_stack(void)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return NULL;
	ptr->size = 0;
	ptr->top = NULL;
	ptr->bottom = NULL;
	return (ptr);
}

/*
 * Allocate memory to the node.
 */

t_node	*init_node()
{
	t_node	*Node;

	Node = (t_node *)malloc(sizeof(t_node));
	if (!Node)
		return (NULL);
	Node->value = 0;
	Node->next = NULL;
	Node->prev = NULL;
	return (Node);
}

/*
 *	Check if there is a node, if there is not already a node:
 *	then put the node to the top of the stack.
 *	Otherwise, put the argument to the next node and connect it
 *	with the previous one, update the top of the stack.
 */

void	connect_nodes(t_node **tmp, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *tmp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *tmp;
		(*tmp)->prev = *node;
		*node = (*node)->next;
	}
}

/* 
 * Set the nodes, acoording to the given arguments,
 * first we split the given arguments, to have
 * a set of array numbers.
 * If no argument, then print an error message.
 * while there is an argument left:
 * init a node, if something is wrong with that:
 * then print an error message.
 * Set the value of the node to the given argument
 * "In digit of course".
 * Connect the nodes, one with another.
 * Grow the stack and free the argument that is set.
 * Finally free all the arguments that are set.
 * Return 1 if everything wen right.
 */

int	set_node(char *argv, t_node **node, t_stack **stack)
{
	int		i;
	char	**args;
	t_node	*tmp;

	args = ft_split(argv, ' ');
	if (!*args || !*args)
		return (0);
	i = -1;
	while (args[++i])
	{
		tmp = init_node();
		if (!tmp)
			print_error();
		tmp->value = ft_atoi(args[i]);
		connect_nodes(&tmp, node, stack);
		(*stack)->size++;
		free(args[i]);
	}
	free(args);
	return (1);
}

/*
 * First constructing of the stack. While there is an argument, send the
 * node adress with the given arguments and the stack to be filled.
 * If something went wron in setting the nodes, print an error message.
 */

void	test_print(t_node **node);

t_node	*fill_stack(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 0;
	while (++i)
	{
		ret = set_node(argv[i], &node, stack);
		if (!ret)
			print_error();
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
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
