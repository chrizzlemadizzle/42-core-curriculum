/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:57:41 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 11:17:19 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	ft_sb(t_stack **b, int print)
{
	t_stack	*temp;

	if (!(*b) || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (print)
		ft_printf("sb\n");
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ft_rb(t_stack **b, int print)
{
	t_stack	*temp;

	if (!(*b) || !(*b)->next)
		return ;
	temp = *b;
	*b = ft_stack_last(*b);
	(*b)->next = temp;
	(*b) = temp->next;
	temp->next = NULL;
	if (print)
		ft_printf("rb\n");
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ft_rrb(t_stack **b, int print)
{
	t_stack	*temp;
	int		size;

	if (!(*b) || !(*b)->next)
		return ;
	size = ft_stack_size(*b);
	temp = *b;
	(*b) = ft_stack_last(*b);
	(*b)->next = temp;
	while (size-- > 2)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	if (print)
		ft_printf("rrb\n");
}
