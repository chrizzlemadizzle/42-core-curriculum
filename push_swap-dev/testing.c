#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	while(stack)
	{
		ft_printf("%i\n", stack->nbr);
		stack = stack->next;
	}
}

void	ft_print_costs(t_stack *stack)
{
	while(stack)
	{
		ft_printf("nbr: %i, costs: (ra, %i), (rra, %i), (rb, %i), (rrb, %i), (rr, %i), (rrr, %i)\n", stack->nbr, stack->ra, stack->rra, stack->rb, stack->rrb, stack->rr, stack->rrr);
		stack = stack->next;
	}
}

void	ft_print_ab(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	if(size_a > size_b)
	{
		while(size_a && size_a > size_b)
		{
			ft_printf("%i\n", a->nbr);
			size_a--;
			a = a->next;
		}
	}
	else if (size_b > size_a)
	{
		while(size_b && size_b > size_a)
		{
			ft_printf("	%i\n", b->nbr);
			size_b--;
			b = b->next;
		}
	}
	while (size_a == size_b && size_a > 0 && size_b > 0)
	{
		ft_printf("%i	%i\n", a->nbr, b->nbr);
		size_a--;
		size_b--;
		a = a->next;
		b = b->next;
	}
	ft_printf("-	-\nA	B\n");
}
