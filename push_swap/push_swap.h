/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:41:00 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/11 11:34:15 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/include/ft_printf.h"
# include "libft/libft.h"

typedef struct s_content
{
	int	index;
	int	number;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	cost;
}		t_content;

typedef struct s_op
{
	int	to_push;
	int	biggest;
	int	smallest;
	int	big_index;
	int	small_index;
	int	i;
	int	cost;
	int	cheapest;
}		t_op;

char	**validate_args(int ac, char **av, int *to_free);
void	destroy_content(void *content);
t_list	*build_stack_a(char **args);
void	print_error_exit(char *str);
void	free_error_exit(char *str, t_list *stack);
void	check_dup(t_list *stack);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	single_swap(t_list **stack, char *str);
void	double_swap(t_list **stack_a, t_list **stack_b, char *str);
void	single_rotate(t_list **stack, char *str);
void	double_rotate(t_list **stack_a, t_list **stack_b, char *str);
void	single_reverse_rotate(t_list **stack, char *str);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b, char *str);
void	push(t_list **stack_pop, t_list **stack_push, char *str);
int		get_index(t_content *content);
int		get_number(t_content *content);
void	sort_negative(t_list **stack_a, t_list **stack_b, int size, int bit);
void	sort_positive(t_list **stack_a, t_list **stack_b, int size, int bit);
int		has_negative(t_list **stack_a);
int		check_sorted(t_list *stack_a);
void	free_args(char **args);
void	free_exit(t_list *stack);
void	print_stack(t_list *stack);
void	sort_advance(t_list **stack_a, t_list **stack_b, int size);
void	sort_3(t_list **stack_a);
int		ft_lstsize(t_list *stack);
void	search_smallest(t_list *tmp, t_content *content);
void	search_position(t_list *stack, t_content *content);
int		smallest_pos(t_list *stack_a, int size);
void	calculate_cost_a(t_list *stack_a, t_list *stack_b, t_op *op);
void	calculate_cost_b(t_list *stack_a, t_list *stack_b, t_op *op);
void	optimised_push_a(t_list **stack_a, t_list **stack_b);
void	optimised_push_b(t_list **stack_a, t_list **stack_b);
void	init_op(t_op *op);
void	to_push(t_list **stack_a, t_list **stack_b, int index, char c);
void	run_op(t_list **stack_a, t_list **stack_b, t_content *content, char c);
void	run_op2(t_list **stack_a, t_list **stack_b, t_content *content, char c);
void	check_double(t_content *content, t_op *op);
void	calculate_rev_b(t_list *stack_a, t_list *stack_b, t_op *op);
void	calculate_rev_a(t_list *stack_a, t_list *stack_b, t_op *op);
void	get_big_small_a(t_list *stack, t_op *op);
void	get_big_small_b(t_list *stack, t_op *op);
void	clear_op(t_content *content);
t_list	*move_stack(t_list *stack, t_op *op, int half);
void	calculate_cost_b2(t_list *stack_a, t_list *stack_b, t_op *op);
void	calculate_cost_a2(t_list *stack_a, t_list *stack_b, t_op *op);
int		get_revcost_a(t_content *content, t_list *stack_a, t_op *op);
int		get_revcost_b(t_content *content, t_list *stack_a, t_op *op);
void	copy_content(t_content *src, t_content *dst, int clear);

#endif