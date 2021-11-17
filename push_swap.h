/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:42:55 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/17 12:27:51 by hsabir           ###   ########.fr       */
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

t_stack	*init_stack(void);
void	ft_error(void);

#endif
