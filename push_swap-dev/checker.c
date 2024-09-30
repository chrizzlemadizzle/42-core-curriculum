/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:32:44 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/30 10:24:39 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_and_terminate(t_stack **a, t_stack **b, char *line)
{
	ft_stack_clear(a);
	ft_stack_clear(b);
	free(line);
	ft_terminate("Error");
}

char	*ft_apply_line(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp("sa\n", line) == 0)
		ft_sa(a, 0);
	else if (ft_strcmp("sb\n", line) == 0)
		ft_sb(b, 0);
	else if (ft_strcmp("ss\n", line) == 0)
		ft_ss(a, b, 0);
	else if (ft_strcmp("pa\n", line) == 0)
		ft_pa(a, b, 0);
	else if (ft_strcmp("pb\n", line) == 0)
		ft_pb(a, b, 0);
	else if (ft_strcmp("ra\n", line) == 0)
		ft_ra(a, 0);
	else if (ft_strcmp("rb\n", line) == 0)
		ft_rb(b, 0);
	else if (ft_strcmp("rr\n", line) == 0)
		ft_rr(a, b, 0);
	else if (ft_strcmp("rra\n", line) == 0)
		ft_rra(a, 0);
	else if (ft_strcmp("rrb\n", line) == 0)
		ft_rrb(b, 0);
	else if (ft_strcmp("rrr\n", line) == 0)
		ft_rrr(a, b, 0);
	else
		ft_clear_and_terminate(a, b, line);
	return (ft_get_next_line(0));
}

void	ft_checker(t_stack **a, t_stack **b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = ft_apply_line(a, b, line);
		free(temp);
	}
	if (*b)
		ft_printf("KO\n");
	else if (!ft_check_sorted_asc(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	a = ft_init_stack(argc, argv);
	if (!a || ft_check_duplicates(a))
	{
		ft_stack_clear(&a);
		ft_terminate("Error");
	}
	line = ft_get_next_line(0);
	if (!line && !ft_check_sorted_asc(a))
		ft_printf("KO\n");
	else if (!line && ft_check_sorted_asc(a))
		ft_printf("OK\n");
	else
		ft_checker(&a, &b, line);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
