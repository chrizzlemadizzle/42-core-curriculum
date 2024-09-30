/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_do.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:57:07 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 12:35:13 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_ra_rb(t_stack **a, t_stack **b, t_stack *current)
{
	while (current->rr--)
	{
		current->ra--;
		current->rb--;
		ft_rr(a, b, 1);
	}
	while (current->ra--)
		ft_ra(a, 1);
	while (current->rb--)
		ft_rb(b, 1);
}

void	ft_do_ra_rrb(t_stack **a, t_stack **b, t_stack *current)
{
	while (current->ra--)
		ft_ra(a, 1);
	while (current->rrb--)
		ft_rrb(b, 1);
}

void	ft_do_rra_rb(t_stack **a, t_stack **b, t_stack *current)
{
	while (current->rra--)
		ft_rra(a, 1);
	while (current->rb--)
		ft_rb(b, 1);
}

void	ft_do_rra_rrb(t_stack **a, t_stack **b, t_stack *current)
{
	while (current->rrr--)
	{
		current->rra--;
		current->rrb--;
		ft_rrr(a, b, 1);
	}
	while (current->rra--)
		ft_rra(a, 1);
	while (current->rrb--)
		ft_rrb(b, 1);
}
