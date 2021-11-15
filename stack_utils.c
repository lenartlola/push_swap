/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:43:11 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/15 12:43:12 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

static t_node	*init_node(void)
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

static void	add_node(t_node **tmp, t_node **node, t_stack **stack)
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

static int	set_node(char *argv, t_node **node, t_stack **stack)
{
	int	i;
	char	**arg;
	t_node	*tmp;

	arg = ft_split(argv, ' ');
	if (!arg || !*arg)
		return (0);
	i = -1;
	while (arg[++i])
	{
		tmp = init_node();
		if (!tmp)
			ft_error();
		tmp->value = ft_atoi(arg[i]);
		add_node(&tmp, node, stack);
		(*stack)->size++;
		free(arg[i]);
	}
	free(arg);
	return (1);
}

t_node	*create_stack(int argc, char **argv, t_stack **stack)
{
	int	i;
	int	ret;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		ret = set_node(argv[i], &node, stack);
		if (!ret)
			ft_error();
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
