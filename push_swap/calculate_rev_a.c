/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rev_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:33:30 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/11 11:39:39 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_revcost_a2(t_content *content, t_list *stack_a, int size)
{
	int	i;
	int	current;
	int	next_big;
	int	next_big_idx;

	i = 0;
	next_big_idx = -1;
	while (stack_a)
	{
		current = get_number(stack_a->content);
		if (current > content->number && (next_big_idx == -1
				|| current < next_big))
		{
			next_big = current;
			next_big_idx = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	content->rra = size - next_big_idx;
}

int	get_revcost_a(t_content *content, t_list *stack_a, t_op *op)
{
	int		size;

	size = ft_lstsize(stack_a);
	get_big_small_a(stack_a, op);
	if (content->number > op->biggest)
	{
		if (op->small_index == 0)
			content->rra = 0;
		else
			content->rra = size - op->small_index;
	}
	else
		get_revcost_a2(content, stack_a, size);
	return (content->cost);
}

void	calculate_rev_a(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	content_b;
	int			half;

	half = ft_lstsize(stack_b) / 2;
	stack_b = move_stack(stack_b, op, half);
	while (stack_b)
	{
		copy_content(stack_b->content, &content_b, 1);
		content_b.rrb = half;
		op->cost = get_revcost_a(&content_b, stack_a, op);
		check_double(&content_b, op);
		if (op->cost < op->cheapest)
		{
			op->cheapest = op->cost;
			op->to_push = op->i;
			copy_content(&content_b, stack_b->content, 0);
		}
		op->i++;
		half--;
		stack_b = stack_b->next;
	}
}
