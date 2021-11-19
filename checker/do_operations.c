/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:02:37 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/19 14:03:37 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include "checker.h"

void	do_push(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("pa", buf))
		push_stack(b, a, 0);
	else if (!ft_strcmp("pb", buf))
		push_stack(a, b, 0);
}

void	do_swap(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("sa", buf))
		swap_stack(a, 0);
	else if (!ft_strcmp("sb", buf))
		swap_stack(b, 0);
	else
		swap_both_stack(a, b, 0);
}

void	do_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("ra", buf))
		rotate_stack(a, 0);
	else if (!ft_strcmp("rb", buf))
		rotate_stack(b, 0);
	else
		rotate_both_stack(a, b, 0);
}

void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("rra", buf))
		reverse_rotate_stack(a, 0);
	else if (!ft_strcmp("rrb", buf))
		reverse_rotate_stack(b, 0);
	else
		reverse_rotate_both_stack(a, b, 0);
}
