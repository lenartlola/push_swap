/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:28:26 by hsabir            #+#    #+#             */
/*   Updated: 2021/11/17 18:55:47 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void);

//*************************Argument checks****************************
static int	check_args_length(char *args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (args[0] == '+' || args[0] == '-')
	{
		i++;
		len--;
	}
	while (args[i] == '0')
		i++;
	while (args[i++])
		len++;
	return (len);
}

// Check if the arguments content only digits
static int	is_numeric(char *arg)
{
	int	i;
	if (!arg)
		return (0);
	i = -1;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while(arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

// Check if the arguments are numbers, and the length of digits
// should not be bigger than 11, as well as not smaller than 0.
int	check_args(char *args)
{
	int	len;

	len = check_args_length(args);
	if (!is_numeric(args) || len > 11 || len < 0)
		return (0);
	else
		return (1);
}

/* I use a special kind of atoi, therefore I'll implement
 * my_atoi function which will handle some error cases.
 */
int	my_atoi(char *args)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_args(args))
		print_error();
	i = 0;
	sign = 1;
	value = 0;
	if (args[i] == '+' || args[i] == '-')
	{
		if (args[i++] == '-')
			sign = -1;
	}
	while (args[i])
		value = value * 10 + (args[i++] - '0');
	value = value * sign;
	if (value > MAX_INT || value < MAX_INT)
		print_error();
	return (value);
}

// A standard error message.
void	print_error(void)
{
	ft_putendl_fd("Error\n", 2);
}

/*
 * Allocate the memory to the stack
 */

t_stack	*init_stack(void)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return NULL;
	ptr->size = 0;
	ptr->top = NULL;
	ptr->bottom = NULL;
	return (ptr);
}

/*
 * Allocate memory to the node.
 */

t_node	*init_node()
{
	t_node	*Node;

	Node = (t_node *)malloc(sizeof(t_node));
	if (!Node)
		return (NULL);
	Node->value = 0;
	Node->next = NULL;
	Node->prev = NULL;
	return (Node);
}

/*
 *	Check if there is a node, if there is not already a node:
 *	then put the node to the top of the stack.
 *	Otherwise, put the argument to the next node and connect it
 *	with the previous one, update the top of the stack.
 */

void	connect_nodes(t_node **tmp, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *tmp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *tmp;
		(*tmp)->prev = *node;
		*node = (*node)->next;
	}
}

/* 
 * Set the nodes, acoording to the given arguments,
 * first we split the given arguments, to have
 * a set of array numbers.
 * If no argument, then print an error message.
 * while there is an argument left:
 * init a node, if something is wrong with that:
 * then print an error message.
 * Set the value of the node to the given argument
 * "In digit of course".
 * Connect the nodes, one with another.
 * Grow the stack and free the argument that is set.
 * Finally free all the arguments that are set.
 * Return 1 if everything wen right.
 */

int	set_node(char *argv, t_node **node, t_stack **stack)
{
	int		i;
	char	**args;
	t_node	*tmp;

	args = ft_split(argv, ' ');
	if (!*args || !*args)
		return (0);
	i = -1;
	while (args[++i])
	{
		tmp = init_node();
		if (!tmp)
			print_error();
		tmp->value = ft_atoi(args[i]);
		connect_nodes(&tmp, node, stack);
		(*stack)->size++;
		free(args[i]);
	}
	free(args);
	return (1);
}

/*
 * First constructing of the stack. While there is an argument, send the
 * node adress with the given arguments and the stack to be filled.
 * If something went wron in setting the nodes, print an error message.
 */

void	test_print(t_node **node);

t_node	*fill_stack(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 0;
	while (++i)
	{
		ret = set_node(argv[i], &node, stack);
		if (!ret)
			print_error();
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
}

// ######################################################
// ############A function to free the stacks.############
// ######################################################
static void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node)
	{
		if (node->next)
			tmp = node->next;
		else
			tmp = NULL;
		free(node);
		if (tmp)
			node = tmp;
		else
			break;
	}
	free(stack);
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

// #######################################################

/*
 * Check if stack a is sorted or not yet.
 */
int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}

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


// ######################################################
// ################ Sorting Algorithms ##################
// ######################################################

// ############### Sort and get middle ##################
// ######################################################

static int	five_sort(int value[])
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[i] > value[j+1])
			{
				tmp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = tmp;
			}
		}
	}
	return (value[2]);
}
int	get_five_mid(t_node *node)
{
	int	i;
	int	value[5];

	i = -1;
	while (++i < 5)
	{
		value[i] = node->value;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (five_sort(value));
}

int	get_min_value(t_node *node, int size)
{
	int	min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

int	get_max_value(t_node *node, int size)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

// ################# Three arguments a ##################
static void	three_top_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->next->value == max)
		{
			reverse_rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
	else
	{
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	three_mid_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->bottom->value == max)
			swap_stack(a, A);
		else
			rotate_stack(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	three_bottom_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->value == max)
			swap_stack(a, A);
		reverse_rotate_stack(a, A);
	}
	else
	{
		if (a->top->value == max)
			swap_stack(a, A);
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate_stack(a, A);
		swap_stack(a, A);
	}
}

void	three_handler_a(int r, t_stack *a)
{
	int	min;
	int	max;

	min = get_min_value(a->top, r);
	max = get_max_value(a->top, r);
	if (a->top->value == min)
		three_top_min_a(a, max);
	else if (a->top->next->value == min)
		three_mid_min_a(a, max);
	else if (a->top->next->next->value == min)
		three_bottom_min_a(a, max);
}

// ############# Three arguments b ###############
void	three_top_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
	else
	{
		swap_stack(b, B);
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
}

void	three_mid_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		reverse_rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
	else
	{
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
}

static void	three_bottom_min_b(t_stack *b, int max)
{
	if (b->top->next->value == max)
		swap_stack(b, B);
}

void	three_handler_b(int r, t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min_value(b->top, r);
	max = get_max_value(b->top, r);
	if (b->top->value == min)
		three_top_min_b(b, max);
	else if (b->top->next->value == min)
		three_mid_min_b(b, max);
	else if (b->top->next->next->value == min)
		three_bottom_min_b(b, max);
	push_stack(b, a, A);
	push_stack(b, a, A);
	push_stack(b, a, A);
}

// ########## Two arguments || Smaller ############
void	two_handler(t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
	{
		if (a->top->value > a->top->next->value)
			swap_stack(a, A);
	}
	else
	{
		if (b->top->value < b->top->next->value)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
}

void	under_three_handler(int r, t_stack *a, t_stack *b, int flag)
{
	if (r == 3)
	{
		if (flag == A)
			three_handler_a(r, a);
		else
			three_handler_b(r, a, b);
	}
	else if (r == 2)
		two_handler(a, b, flag);
	else if (r == 1)
	{
		if (flag == B)
			push_stack(b, a, A);
	}
}

// ############# Initialize the values ##############
void	init_values(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}


// ################ above five ######################
static int	exception(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		under_three_handler(r, a, b, A);
		return (0);
	}
}

void	a_to_b(int r, t_stack *a, t_stack *b, int *count)
{
	int		tmp;
	t_value	var;

	if (!exceptions(r, a, b))
		return ;
	init_values(&var);
}


// ################# Five arguments ###################
void	five_handler(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_five_mid(a->top);
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
	three_handler_b(3, a);
	two_handler(a, b, B);
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

/*
 * Declare the stacks and take the arguments,
 * if no argument is given return an error message.
 * while there is an argument left init the stack a,
 * and fill it with the arguments.
 */


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	i = 0;
	if (argc > 1)
	{
		a = init_stack();
		a->top = fill_stack(argc, argv, &a);
		b = init_stack();
		if (is_sorted(a))
		{
			free_all(a, b);
			return (0);
		}
		push_swap(a, b);
		free_all(a, b);
	}
}
