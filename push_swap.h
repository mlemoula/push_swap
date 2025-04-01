/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:00:05 by mlemoula          #+#    #+#             */
/*   Updated: 2025/04/01 16:10:40 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stacks
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*operations;
}	t_stacks;

void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

int		check_param(int argc, char **argv);
long	ft_atoi_custom(const char *nptr);
int		stack_list(char **argv, int n, t_list **stack_a);
void	sort(t_stacks *stacks);
void	clean_ext(t_stacks *stacks, char **argv, int split_flag, int err_flag);
void	big_sort(t_stacks *stacks);
int		args_are_sorted(char **argv, int split_flag);
int		stack_is_sorted(t_list *stack);
int		get_max_index(t_list *stack);
void	stock_ope(char *ope_name, t_stacks *stacks);
void	print_list(t_stacks *stacks);

#endif