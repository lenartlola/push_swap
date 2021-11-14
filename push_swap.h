#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <libft/libft.h>

typedef struct	s_node	t_node;

typedef struct	s_node
{
	int	value;
	t_node	*prev;
	t_node	*next;
}	t_node;

typedef struct	s_value
{
	long	piv_big;
	long	piv_small;
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_value;

typedef struct	s_stack
{
	int	size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

t_stack	*init_stack(void);
void	ft_error(void);

#endif
