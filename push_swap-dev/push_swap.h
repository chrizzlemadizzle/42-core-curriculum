/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:01:52 by cdahne            #+#    #+#             */
/*   Updated: 2024/09/23 16:22:14 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
}	t_stack;

void	ft_terminate(char *errmsg);
t_stack	*ft_init_stack(long size, char **content);
int		ft_init_stack_supp(t_stack **stack, char *content);
t_stack	*ft_param_as_str(char *str);
void	ft_print_stack(t_stack *stack);
t_stack	*ft_new_stack(int nbr);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	ft_stack_clear(t_stack **stack);
int		ft_stack_size(t_stack *stack);
int		ft_arg_is_nbr(char *arg);
int		ft_check_duplicates(t_stack *stack);
int		ft_check_sorted_asc(t_stack *stack);
int		ft_check_sorted_desc(t_stack *stack);
void	ft_sort(t_stack **a);
void	ft_sa(t_stack **a, int print);
void	ft_ra(t_stack **a, int print);
void	ft_rra(t_stack **a, int print);
void	ft_pb(t_stack **a, t_stack **b, int print);
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_sb(t_stack **b, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rrb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	ft_print_ab(t_stack *a, t_stack *b);
void	ft_print_costs(t_stack *stack);
int		ft_stack_max(t_stack *stack);
int		ft_stack_min(t_stack *stack);
int		ft_stack_neighbour_desc(int nbr, t_stack *stack);
int		ft_stack_neighbour_asc(int nbr, t_stack *stack);
void	ft_calc_costs(t_stack *a, t_stack *b);
int		ft_cost_r_desc(int nbr, t_stack *stack);
int		ft_cost_r_asc(int nbr, t_stack *stack);
void	ft_reset_costs(t_stack *stack);
int		ft_filter_best_rot(t_stack *a);
void	ft_do_best_rot(t_stack **a, t_stack **b, int min);
int		ft_costs_ra_rb(t_stack *stack);
int		ft_costs_ra_rrb(t_stack *stack);
int		ft_costs_rra_rb(t_stack *stack);
int		ft_costs_rra_rrb(t_stack *stack);
void	ft_do_ra_rb(t_stack **a, t_stack **b, t_stack *current);
void	ft_do_ra_rrb(t_stack **a, t_stack **b, t_stack *current);
void	ft_do_rra_rb(t_stack **a, t_stack **b, t_stack *current);
void	ft_do_rra_rrb(t_stack **a, t_stack **b, t_stack *current);
#endif
