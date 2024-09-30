/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:01:39 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 16:23:00 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_init_stack(argc, argv);
	if (ft_check_duplicates(a))
	{
		ft_stack_clear(&a);
		ft_terminate("Error");
	}
	if (!ft_check_sorted_asc(a))
		ft_sort(&a);
	ft_stack_clear(&a);
	return (0);
}
