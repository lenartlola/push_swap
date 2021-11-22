/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:28:26 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/22 14:07:55 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ############# Initialize the values ##############
void	init_values(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

void	select_pivots(int r, t_stack *stack, t_value *var)
{
	long	min;
	long	max;

	min = get_min_value(stack->top, r);
	max = get_max_value(stack->top, r);
	var->big_pivot = (min + max) / 2;
	var->small_pivot = (min + var->big_pivot) / 2;
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	if (a->size == 5)
		five_handler(a, b);
	else
		a_to_b(a->size, a, b, &count);
}
