/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:48:04 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/02 13:17:51 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_sorted(t_stack *a)
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
			break ;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}

void	check_operations(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(buf, "sa\n", 4))
		do_swap(buf, a, b);
	else if (!ft_strncmp(buf, "sb\n", 4))
		do_swap(buf, a, b);
	else if (!ft_strncmp(buf, "ss\n", 4))
		do_swap(buf, a, b);
	else if (!ft_strncmp(buf, "pa\n", 4))
		do_push(buf, a, b);
	else if (!ft_strncmp(buf, "pb\n", 4))
		do_push(buf, a, b);
	else if (!ft_strncmp(buf, "ra\n", 4))
		do_rotate(buf, a, b);
	else if (!ft_strncmp(buf, "rb\n", 4))
		do_rotate(buf, a, b);
	else if (!ft_strncmp(buf, "rr\n", 4))
		do_rotate(buf, a, b);
	else if (!ft_strncmp(buf, "rra\n", 5))
		do_reverse_rotate(buf, a, b);
	else if (!ft_strncmp(buf, "rrb\n", 5))
		do_reverse_rotate(buf, a, b);
	else if (!ft_strncmp(buf, "rrr\n", 5))
		do_reverse_rotate(buf, a, b);
	else
		print_error();
}

void	checker(t_stack *a, t_stack *b)
{
	char	*buf;

	buf = get_next_line(0);
	while (buf)
	{
		check_operations(buf, a, b);
		free(buf);
		buf = get_next_line(0);
	}
	free(buf);
	if (is_sorted(a) && !b->top)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
