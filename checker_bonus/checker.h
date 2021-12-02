/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:48:25 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/02 13:38:51 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"
# include "libft/libft.h"

void	checker(t_stack *a, t_stack *b);

t_stack	*init_stack(void);
t_node	*make_stack(int argc, char **argv, t_stack **stack);

void	print_error(void);
int		check_args(char *arg);
void	check_duplicated(t_node *a);
int		my_atoi(char *arg);

void	swap_stack(t_stack *stack, int flag);
void	swap_both_stack(t_stack *a, t_stack *b, int flag);
void	push_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_both_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_both_stack(t_stack *a, t_stack *b, int flag);
t_node	*fill_stack(int argc, char **argv, t_stack **stack);

void	do_push(char *buf, t_stack *a, t_stack *b);
void	do_swap(char *buf, t_stack *a, t_stack *b);
void	do_rotate(char *buf, t_stack *a, t_stack *b);
void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b);

void	free_all(t_stack *a, t_stack *b);

#endif
