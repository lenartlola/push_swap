/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:28:26 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/16 18:50:56 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putendl_fd("Error\n", 2);
}

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
 *	Check if there is a node, if so then connect with the current.
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

int	set_node(char *argv, t_node **node, t_stack **stack)
{
	int		i;
	char	**args;
	t_node	*tmp;

	args = ft_split(argv, ' ');
	if (!*args)
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;
	int	i;

	i = 0;
	if (argc < 2)
		print_error();
	while (++i < argc)
	{
		a = init_stack();
		a->top = fill_stack(argc, argv, &a);

	}
	while (a != NULL)
	{
		ft_printf("%d\n", a->size);
	}
}
