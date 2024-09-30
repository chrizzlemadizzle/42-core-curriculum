/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:59:29 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 12:34:00 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	ft_pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	if (print)
		ft_printf("pb\n");
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	ft_pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	if (print)
		ft_printf("pa\n");
}

// sa and sb at the same time.
void	ft_ss(t_stack **a, t_stack **b, int print)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	if (print)
		ft_printf("ss\n");
}

// ra and rb at the same time.
void	ft_rr(t_stack **a, t_stack **b, int print)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	if (print)
		ft_printf("rr\n");
}

// rra and rrb at the same time.
void	ft_rrr(t_stack **a, t_stack **b, int print)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
