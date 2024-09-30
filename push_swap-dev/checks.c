/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:00:20 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/30 11:04:16 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_is_nbr(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg) && *arg != '-')
			return (0);
		arg++;
	}
	return (1);
}

int	ft_check_duplicates(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->nbr == stack->nbr)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_check_sorted_asc(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_check_sorted_desc(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr < stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
