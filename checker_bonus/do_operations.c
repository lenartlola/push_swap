/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:02:37 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/02 13:15:55 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_push(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(buf, "pa\n", 4))
		push_stack(b, a, 0);
	else if (!ft_strncmp(buf, "pb\n", 4))
		push_stack(a, b, 0);
}

void	do_swap(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(buf, "sa\n", 4))
		swap_stack(a, 0);
	else if (!ft_strncmp(buf, "sb\n", 4))
		swap_stack(b, 0);
	else
		swap_both_stack(a, b, 0);
}

void	do_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(buf, "ra\n", 4))
		rotate_stack(a, 0);
	else if (!ft_strncmp(buf, "rb\n", 4))
		rotate_stack(b, 0);
	else
		rotate_both_stack(a, b, 0);
}

void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(buf, "rra\n", 5))
		reverse_rotate_stack(a, 0);
	else if (!ft_strncmp(buf, "rrb\n", 5))
		reverse_rotate_stack(b, 0);
	else
		reverse_rotate_both_stack(a, b, 0);
}
