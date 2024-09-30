/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:59:17 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 10:59:17 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	ft_sa(t_stack **a, int print)
{
	t_stack	*temp;

	if (!(*a) || !(*a)->next)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (print)
		ft_printf("sa\n");
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ft_ra(t_stack **a, int print)
{
	t_stack	*temp;

	if (!(*a) || !(*a)->next)
		return ;
	temp = *a;
	*a = ft_stack_last(*a);
	(*a)->next = temp;
	(*a) = temp->next;
	temp->next = NULL;
	if (print)
		ft_printf("ra\n");
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	ft_rra(t_stack **a, int print)
{
	t_stack	*temp;
	int		size;

	if (!(*a) || !(*a)->next)
		return ;
	size = ft_stack_size(*a);
	temp = *a;
	*a = ft_stack_last(*a);
	(*a)->next = temp;
	while (size-- > 2)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	if (print)
		ft_printf("rra\n");
}
