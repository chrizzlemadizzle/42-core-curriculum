/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:00:09 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 16:23:09 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finish_a(t_stack **stack)
{
	int	min;
	int	ra;
	int	rra;

	min = ft_stack_min(*stack);
	ra = ft_cost_r_asc(min - 1, *stack);
	rra = ft_stack_size(*stack) - ra;
	if (ra <= rra)
		while (ra--)
			ft_ra(stack, 1);
	else
		while (rra--)
			ft_rra(stack, 1);
}

void	ft_refill_a(t_stack **a, t_stack **b)
{
	int	ra;
	int	rra;
	int	size_a;

	while (*b)
	{
		size_a = ft_stack_size(*a);
		ra = ft_cost_r_asc((*b)->nbr, *a);
		rra = size_a - ra;
		if (ra <= rra)
		{
			while (ra--)
				ft_ra(a, 1);
		}
		else
			while (rra--)
				ft_rra(a, 1);
		ft_pa(a, b, 1);
	}
}

// sort a stack if only three elements remain.
void	ft_sort_triplet(t_stack **triplet)
{
	if ((*triplet)->nbr == ft_stack_max(*triplet))
	{
		if (ft_check_sorted_desc(*triplet))
		{
			ft_sa(triplet, 1);
			ft_rra(triplet, 1);
		}
		else
			ft_ra(triplet, 1);
	}
	else if ((*triplet)->nbr == ft_stack_min(*triplet))
	{
		ft_sa(triplet, 1);
		ft_ra(triplet, 1);
	}
	else
	{
		if ((*triplet)->next->nbr == ft_stack_max(*triplet))
			ft_rra(triplet, 1);
		else
			ft_sa(triplet, 1);
	}
}

void	ft_fill_b(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		ft_calc_costs(*a, *b);
		ft_do_best_rot(a, b, ft_filter_best_rot(*a));
		ft_pb(a, b, 1);
	}
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_stack_size(*a) == 2)
		ft_sa(a, 1);
	else
	{
		if (ft_stack_size(*a) > 3 && !ft_check_sorted_asc(*a))
			ft_pb(a, &b, 1);
		if (ft_stack_size(*a) > 3 && !ft_check_sorted_asc(*a))
			ft_pb(a, &b, 1);
		if (ft_stack_size(*a) > 3 && !ft_check_sorted_asc(*a))
			ft_fill_b(a, &b);
		if (!ft_check_sorted_asc(*a))
			ft_sort_triplet(a);
		ft_refill_a(a, &b);
		if (!ft_check_sorted_asc(*a))
			ft_finish_a(a);
	}
}
