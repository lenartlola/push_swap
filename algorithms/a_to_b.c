/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:34:34 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/19 13:36:03 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	exceptions(int r, t_stack *a, t_stack *b)
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
	else
		return (1);
}

/*
 * If the top of the stack a is bigger than the big_pivot,
 * then rotate the stack a and add 1 to var->ra.
 * Othwewise, push the top of the stack a to the stack b,
 * and add 1 to var->pb.
 * If the top of the stack b is bigger than the small_pivot,
 * then rotate the stack b, we also have to add 1 to rb, keeping track
 * of the operations been made.
 */

static void	push_rotate_a(t_stack *a, t_stack *b, t_value *var)
{
	if (a->top->value > var->big_pivot)
	{
		rotate_stack(a, A);
		var->ra++;
	}
	else
	{
		push_stack(a, b, B);
		var->pb++;
		if (b->top->value > var->small_pivot)
		{
			rotate_stack(b, B);
			var->rb++;
		}
	}
}

static void	back_to_orig_ra(t_stack *a, t_stack *b, int *count, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	if ((*count) > 0)
	{
		while (rrr--)
			reverse_rotate_both_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}

static void	back_to_orig_rb(t_stack *a, t_stack *b, int *count, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	if ((*count) > 0)
	{
		while (rrr--)
			reverse_rotate_both_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	else
	{
		rrr = var->rb;
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}

/*
 * Select two pivots,
 * big_pivot = (min + max) / 2
 * small_pivot = (min + big_pivot) / 2
 * While there is size of stack a, do the push_rotate_a.
 * Call the function recursively.
 * a_to_b(number of ra times)(1)
 * b_to_a(number of rb times)(2)
 * b_to_a(number of pb - rb times)(3)
 * After counting ra and rb, we check if ra is bigger than
 * rb, if so, it means that ra left and so we have to repeat the process
 * as long as it left values.
 */

void	a_to_b(int r, t_stack *a, t_stack *b, int *count)
{
	int		tmp;
	t_value	var;

	if (!exceptions(r, a, b))
		return ;
	init_values(&var);
	select_pivots(r, a, &var);
	tmp = r;
	while (tmp--)
		push_rotate_a(a, b, &var);
	if (var.ra > var.rb)
		back_to_orig_ra(a, b, count, &var);
	else
		back_to_orig_rb(a, b, count, &var);
	a_to_b(var.ra, a, b, count);
	b_to_a(var.rb, a, b, count);
	b_to_a(var.pb - var.rb, a, b, count);
}
