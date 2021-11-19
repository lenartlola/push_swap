/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:27:29 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/19 17:13:57 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * Allocate the memory to the stack
 */

t_stack	*init_stack(void)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
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
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
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
		tmp->value = my_atoi(args[i]);
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

t_node	*fill_stack(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
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

