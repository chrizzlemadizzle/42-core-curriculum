/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:53:32 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 10:53:32 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_costs(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		stack->ra = INT_MAX;
		stack->rra = INT_MAX;
		stack->rb = INT_MAX;
		stack->rrb = INT_MAX;
		stack->rr = INT_MAX;
		stack->rrr = INT_MAX;
		stack = stack->next;
	}
}

int	ft_costs_ra_rb(t_stack *stack)
{
	int	ra;
	int	rb;

	stack->rr = 0;
	ra = stack->ra;
	rb = stack->rb;
	while (ra > 0 && rb > 0)
	{
		stack->rr++;
		ra--;
		rb--;
	}
	return (ra + rb + stack->rr);
}

int	ft_costs_ra_rrb(t_stack *stack)
{
	return (stack->ra + stack->rrb);
}

int	ft_costs_rra_rb(t_stack *stack)
{
	return (stack->rra + stack->rb);
}

int	ft_costs_rra_rrb(t_stack *stack)
{
	int	rra;
	int	rrb;

	stack->rrr = 0;
	rra = stack->rra;
	rrb = stack->rrb;
	while (rra > 0 && rrb > 0)
	{
		stack->rrr++;
		rra--;
		rrb--;
	}
	return (rra + rrb + stack->rrr);
}
