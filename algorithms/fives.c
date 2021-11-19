/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fives.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:56:11 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/19 13:39:34 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_five_handler_a(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_five(a->top);
	while (size--)
	{
		if (a->top->value < mid)
		{
			push_stack(a, b, B);
			push++;
		}
		else
		{
			rotate_stack(a, A);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(a, A);
}

static void	sort_five_handler_b(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_five(b->top);
	while (size--)
	{
		if (b->top->value >= mid)
		{
			push_stack(b, a, A);
			push++;
		}
		else
		{
			rotate_stack(b, B);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(b, B);
}

void	sort_five_handler(int size, t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
		sort_five_handler_a(size, a, b);
	else
		sort_five_handler_b(size, a, b);
	three_handler_a(3, a);
	two_handler(a, b, B);
}

void	five_handler(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_mid_five(a->top);
	while (1)
	{
		if (a->top->value < mid)
		{
			push_stack(a, b, B);
			pb++;
		}
		else
			rotate_stack(a, A);
		if (pb == 2)
			break ;
	}
	three_handler_a(3, a);
	two_handler(a, b, B);
}
