/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemoula <mlemoula@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:00:05 by mlemoula          #+#    #+#             */
/*   Updated: 2025/03/13 15:58:34 by mlemoula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
// # include "stdio.h"
// # include <limits.h>

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

typedef struct s_stacks {
	t_list	*stack_a;
	t_list	*stack_b;
} t_stacks;

int		check_param(int argc, char **argv);
int		stack_list(char **argv, int n, t_list **stack_a);
void	sort(t_stacks *stacks);
void	free_stacks(t_stacks *stacks);
void	free_split(char **argv, int flag);
void	error(t_stacks *stacks, char **argv, int split_flag);
void	clean_exit(t_stacks *stacks, char **argv, int split_flag);
void	big_sort(t_stacks *stacks);
void	small_sort(t_list **stack_a, int stack_size);
// int		get_max_index(t_list *stack);
// int		get_min_index(t_list *stack);
void	min_on_top(t_list **stack);
int		is_sorted(char **argv, int split_flag);

// pour tests
# include <stdio.h>
void	print_stack(t_stacks stacks);
void	print_list(t_list *stack);
// int		split_argv(char ***argv, int *flag, int argc);
///

#endif