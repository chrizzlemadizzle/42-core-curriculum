/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:58:12 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 16:26:23 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_max(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	ft_stack_min(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

t_stack	*ft_param_as_str(char *str)
{
	t_stack	*stack;
	char	**temp;
	int		i;

	stack = NULL;
	temp = ft_split(str, ' ');
	i = 0;
	while (temp[i])
	{
		if (!ft_init_stack_supp(&stack, temp[i]))
			break ;
		i++;
	}
	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (stack);
}

int	ft_init_stack_supp(t_stack **stack, char *content)
{
	long	nbr;

	if (!ft_arg_is_nbr(content))
	{
		ft_stack_clear(stack);
		return (0);
	}
	nbr = ft_atoi(content);
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		ft_stack_clear(stack);
		return (0);
	}
	ft_stack_add_back(stack, ft_new_stack(nbr));
	return (1);
}

t_stack	*ft_init_stack(long size, char **content)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (size < 2)
		exit(0);
	if (size == 2)
	{
		stack = ft_param_as_str(content[i]);
		if (!stack)
			ft_terminate("Error");
	}
	else
	{
		while (i < size)
		{
			if (!ft_init_stack_supp(&stack, content[i]))
				ft_terminate("Error");
			i++;
		}
	}
	return (stack);
}
