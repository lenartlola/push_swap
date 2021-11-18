/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:57:14 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/18 16:57:39 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_handler(t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
	{
		if (a->top->value > a->top->next->value)
			swap_stack(a, A);
	}
	else
	{
		if (b->top->value < b->top->next->value)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
}

void	under_three_handler(int r, t_stack *a, t_stack *b, int flag)
{
	if (r == 3)
	{
		if (flag == A)
			three_handler_a(r, a);
		else
			three_handler_b(r, a, b);
	}
	else if (r == 2)
		two_handler(a, b, flag);
	else if (r == 1)
	{
		if (flag == B)
			push_stack(b, a, A);
	}
}
