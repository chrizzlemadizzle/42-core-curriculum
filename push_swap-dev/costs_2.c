/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:57:18 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 10:57:32 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_best_rot(t_stack **a, t_stack **b, int min)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (min == ft_costs_ra_rb(temp))
			ft_do_ra_rb(a, b, temp);
		else if (min == ft_costs_rra_rb(temp))
			ft_do_rra_rb(a, b, temp);
		else if (min == ft_costs_ra_rrb(temp))
			ft_do_ra_rrb(a, b, temp);
		else if (min == ft_costs_rra_rrb(temp))
			ft_do_rra_rrb(a, b, temp);
		else
		{
			temp = temp->next;
			continue ;
		}
		break ;
	}
}

int	ft_filter_best_rot(t_stack *a)
{
	int	min;

	min = INT_MAX;
	while (a)
	{
		if (min > ft_costs_ra_rb(a))
			min = ft_costs_ra_rb(a);
		else if (min > ft_costs_ra_rrb(a))
			min = ft_costs_ra_rrb(a);
		else if (min > ft_costs_rra_rb(a))
			min = ft_costs_rra_rb(a);
		else if (min > ft_costs_rra_rrb(a))
			min = ft_costs_rra_rrb(a);
		a = a->next;
	}
	return (min);
}
