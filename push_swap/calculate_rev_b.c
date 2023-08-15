/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rev_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:33:30 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/11 11:39:48 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_op(t_content *content)
{
	content->ra = 0;
	content->rb = 0;
	content->rr = 0;
	content->rra = 0;
	content->rrb = 0;
	content->rrr = 0;
}

void	get_revcost_b2(t_content *content, t_list *stack_b, int size)
{
	int	i;
	int	current;
	int	next_small;
	int	next_small_idx;

	i = 0;
	next_small_idx = -1;
	while (stack_b)
	{
		current = get_number(stack_b->content);
		if (current < content->number && (next_small_idx == -1
				|| current > next_small))
		{
			next_small = current;
			next_small_idx = i;
		}
		i++;
		stack_b = stack_b->next;
	}
	content->rrb = size - next_small_idx;
}

int	get_revcost_b(t_content *content, t_list *stack_b, t_op *op)
{
	int		size;

	size = ft_lstsize(stack_b);
	get_big_small_b(stack_b, op);
	if (content->number < op->smallest)
	{
		if (op->big_index == 0)
			content->rrb = 0;
		else
			content->rrb = size - op->big_index;
	}
	else
		get_revcost_b2(content, stack_b, size);
	return (content->cost);
}

t_list	*move_stack(t_list *stack, t_op *op, int half)
{
	op->i = 0;
	if (ft_lstsize(stack) % 2 != 0)
	{
		while (op->i < half + 1)
		{
			stack = stack->next;
			op->i++;
		}
	}
	else
	{
		while (op->i < half)
		{
			stack = stack->next;
			op->i++;
		}
	}
	return (stack);
}

void	calculate_rev_b(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	content_a;
	int			half;

	half = ft_lstsize(stack_a) / 2;
	stack_a = move_stack(stack_a, op, half);
	while (stack_a)
	{
		copy_content(stack_a->content, &content_a, 1);
		content_a.rra = half;
		op->cost = get_revcost_b(&content_a, stack_b, op);
		check_double(&content_a, op);
		if (op->cost < op->cheapest)
		{
			op->cheapest = op->cost;
			op->to_push = op->i;
			copy_content(&content_a, stack_a->content, 0);
		}
		op->i++;
		half--;
		stack_a = stack_a->next;
	}
}
