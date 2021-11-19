/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:42:55 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/19 16:40:55 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define A 1
# define B 2
# define ALL 3

typedef struct	s_node	t_node;
typedef struct	s_value	t_value;

struct	s_node
{
	int	value;
	t_node	*prev;
	t_node	*next;
};

typedef struct	s_stack
{
	int	size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

struct	s_value
{
	long	big_pivot;
	long	small_pivot;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
};

t_stack	*init_stack(void);
void	ft_error(void);

// PUSH_SWAP
void	push_swap(t_stack *a, t_stack *b);
void	select_pivots(int r, t_stack *stack, t_value *var);
void	init_values(t_value *var);
int		is_sorted(t_stack *a);

// FREE
void	free_all(t_stack *a, t_stack *b);

// OPERATIONS
void	push_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_both_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_both_stack(t_stack *a, t_stack *b, int flag);
void	swap_stack(t_stack *stack, int flag);
void	swap_both_stack(t_stack *a, t_stack *b, int flag);

// STACK UTILS
t_node	*fill_stack(int argc, char **argv, t_stack **stack);
int		set_node(char *argv, t_node **node, t_stack **stack);
void	connect_nodes(t_node **tmp, t_node **node, t_stack **stack);

//CHECK UTILS
void		check_duplicated(t_node *a);
int			check_args(char *args);
t_node	*init_node();
t_stack	*init_stack(void);
int	my_atoi(char *args);

// ALGORITHMS
void	a_to_b(int r, t_stack *a, t_stack *b, int *count);
void	b_to_a(int r, t_stack *a, t_stack *b, int *count);
void	five_handler(t_stack *a, t_stack *b);
void	sort_five_handler(int size, t_stack *a, t_stack *b, int flag);
void	three_handler_a(int r, t_stack *a);
void	three_handler_b(int r, t_stack *a, t_stack *b);
void	three_bottom_min_b(t_stack *b, int max);
void	three_mid_min_b(t_stack *b, int max);
void	three_top_min_b(t_stack *b, int max);
void	under_three_handler(int r, t_stack *a, t_stack *b, int flag);
void	two_handler(t_stack *a, t_stack *b, int flag);

// MIN_MID_MAX
int	get_max_value(t_node *node, int size);
int	get_min_value(t_node *node, int size);
int	get_mid_five(t_node *node);

void		print_error(void);

#endif
