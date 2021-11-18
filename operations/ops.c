#include "../push_swap.h"

// ######################################################
// #################### Operations ######################
// ######################################################
void	swap_stack(t_stack *stack, int flag)
{
	t_node	*tmp;
	t_node	*top_next;

	if (stack->size < 2)
		return ;
	top_next = stack->top->next;
	tmp = stack->top;
	if (stack->size > 2)
		top_next->next->prev = stack->top;
	tmp->next = top_next->next;
	stack->top = top_next;
	stack->top->prev = NULL;
	stack->top->next = tmp;
	tmp->prev = stack->top;
	if (stack->size == 2)
		stack->bottom = stack->top->next;
	if (flag == A)
		ft_putendl_fd("sa", 1);
	else if (flag == B)
		ft_putendl_fd("sb", 1);
}

void	reverse_rotate_stack(t_stack *stack, int flag)
{
	t_node	*tmp;
	t_node	*bottom_prev;

	if (stack->size)
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

// push and pop respectevly from a stack to a stack.
static void	from_size_one(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = to->bottom;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

static void	push_pop(t_stack *from, t_stack *to)
{
	if (from->size == 1)
		from_size_one(from, to);
	else
	{
		if (to->size == 0)
		{
			to->top = from->top;
			to->bottom = to->bottom;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	to->size++;
	from->size--;
}

void	push_stack(t_stack *from, t_stack *to, int flag)
{
	if (from->size == 0)
		return ;
	push_pop(from, to);
	if (flag == A)
		ft_putendl_fd("pa", 1);
	else if (flag == B)
		ft_putendl_fd("pb", 1);
}

