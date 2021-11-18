/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:42:55 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/18 18:19:53 by hsabir           ###   ########.fr       */
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
	long	piv_big;
	long	piv_small;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}	t_value;

t_stack	*init_stack(void);
void	ft_error(void);

// OPERATIONS
void	push_stack(t_stack *from, t_stack *to, int flag);
static void	push_pop(t_stack *from, t_stack *to);
static void	from_size_one(t_stack *from, t_stack *to);

// STACK UTILS
t_node	*fill_stack(int argc, char **argv, t_stack **stack);
int	set_node(char *argv, t_node **node, t_stack **stack);
void	connect_nodes(t_node **tmp, t_node **node, t_stack **stack);

//CHECK UTILS
void	check_duplicated(t_node *a);
int	check_args(char *args);
static int	is_numeric(char *arg);
static int	check_args_length(char *args);

#endif
