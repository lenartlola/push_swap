#include "push_swap.h"

void	ft_error(void)
{
	ft_putendl_fd("ERROR", 2);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = init_stack();
		a->top = make_stack(argc, argv, &a);
		check_duplicate(a->top);
		b = init_stack();
	}
}
