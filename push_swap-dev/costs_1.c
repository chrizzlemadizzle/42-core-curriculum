/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:53:53 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 10:56:03 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_neighbour_asc(int nbr, t_stack *stack)
{
	int		cost;
	t_stack	*first;
	t_stack	*last;

	first = stack;
	last = ft_stack_last(stack);
	cost = 0;
	while (first && last)
	{
		if (first->nbr > nbr && last->nbr < nbr)
		{
			break ;
		}
		last = first;
		first = first->next;
		cost++;
	}
	return (cost);
}

int	ft_cost_r_asc(int nbr, t_stack *stack)
{
	int		cost;
	int		stack_max;
	int		stack_min;
	int		stack_size;
	t_stack	*temp;

	temp = stack;
	cost = 0;
	stack_max = ft_stack_max(stack);
	stack_min = ft_stack_min(stack);
	stack_size = ft_stack_size(stack);
	if (nbr > stack_max || nbr < stack_min)
	{
		while (stack)
		{
			if (stack->nbr == stack_min)
				break ;
			cost++;
			stack = stack->next;
		}
	}
	else
		cost = ft_stack_neighbour_asc(nbr, temp);
	return (cost);
}

int	ft_stack_neighbour_desc(int nbr, t_stack *stack)
{
	int		cost;
	t_stack	*first;
	t_stack	*last;

	first = stack;
	last = ft_stack_last(stack);
	cost = 0;
	while (first && last)
	{
		if (first->nbr < nbr && last->nbr > nbr)
		{
			break ;
		}
		last = first;
		first = first->next;
		cost++;
	}
	return (cost);
}

// calculate costs for rotating stack until max number is on top
// check if reverse rotation yields lower costs
// add 1 for the push action
int	ft_cost_r_desc(int nbr, t_stack *stack)
{
	int		cost;
	int		stack_max;
	int		stack_min;
	int		stack_size;
	t_stack	*temp;

	temp = stack;
	cost = 0;
	stack_max = ft_stack_max(stack);
	stack_min = ft_stack_min(stack);
	stack_size = ft_stack_size(stack);
	if (nbr > stack_max || nbr < stack_min)
	{
		while (stack)
		{
			if (stack->nbr == stack_max)
				break ;
			cost++;
			stack = stack->next;
		}
	}
	else
		cost = ft_stack_neighbour_desc(nbr, temp);
	return (cost);
}

void	ft_calc_costs(t_stack *a, t_stack *b)
{
	int			size_a;
	int			size_b;
	int			i;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	i = -1;
	while (a)
	{
		a->ra = ++i;
		a->rra = size_a - a->ra;
		a->rb = ft_cost_r_desc(a->nbr, b);
		a->rrb = size_b - a->rb;
		a = a->next;
	}
}
