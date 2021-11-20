/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 09:48:09 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/20 11:21:24 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
 * ###############################################
 *  ############## Reverse_Rotate ###############
 * ###############################################
 */

void	reverse_rotate_stack(t_stack *stack, int flag)
{
	t_node	*tmp;
	t_node	*bottom_prev;

	if (stack->size < 2)
		return ;
	tmp = stack->bottom;
	bottom_prev = stack->bottom->prev;
	stack->top->prev = tmp;
	tmp->next = stack->top;
	tmp->prev = NULL;
	stack->top = tmp;
	stack->bottom = bottom_prev;
	stack->bottom->next = NULL;
	if (flag == A)
		ft_putendl_fd("rra", 1);
	else if (flag == B)
		ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_both_stack(t_stack *a, t_stack *b, int flag)
{
	reverse_rotate_stack(a, flag);
	reverse_rotate_stack(b, flag);
	if (flag == ALL)
		ft_putendl_fd("rrr", 1);
}

/*
 * #############################################
 *  ################ Rotate #################
 * #############################################
 */

/* 
 * Applied if only the stack contains more than one node.
 */

void	rotate_stack(t_stack *stack, int flag)
{
	t_node	*tmp;
	t_node	*top_next;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	top_next = stack->top->next;
	stack->bottom->next = tmp;
	tmp->prev = stack->bottom;
	tmp->next = NULL;
	stack->bottom = tmp;
	stack->top = top_next;
	stack->top->prev = NULL;
	if (flag == A)
		ft_putendl_fd("ra", 1);
	else if (flag == B)
		ft_putendl_fd("rb", 1);
}

void	rotate_both_stack(t_stack *a, t_stack *b, int flag)
{
	rotate_stack(a, flag);
	rotate_stack(b, flag);
	if (flag == ALL)
		ft_putendl_fd("rr", 1);
}
