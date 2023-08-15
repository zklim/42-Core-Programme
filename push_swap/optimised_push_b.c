/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_push_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:04:21 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 17:09:50 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_op2(t_list **stack_a, t_list **stack_b, t_content *content, char c)
{
	if (content->rrb)
	{
		single_reverse_rotate(stack_b, "rrb\n");
		content->rrb--;
	}
	else if (content->rrr)
	{
		double_reverse_rotate(stack_a, stack_b, "rrr\n");
		content->rrr--;
	}
	else if (c == 'a')
	{
		push(stack_b, stack_a, "pa\n");
		return ;
	}
	else if (c == 'b')
	{
		push(stack_a, stack_b, "pb\n");
		return ;
	}
	else
		return ;
	run_op2(stack_a, stack_b, content, c);
}

void	run_op(t_list **stack_a, t_list **stack_b, t_content *content, char c)
{
	if (content->ra)
	{
		single_rotate(stack_a, "ra\n");
		content->ra--;
	}
	else if (content->rb)
	{
		single_rotate(stack_b, "rb\n");
		content->rb--;
	}
	else if (content->rr)
	{
		double_rotate(stack_a, stack_b, "rr\n");
		content->rr--;
	}
	else if (content->rra)
	{
		single_reverse_rotate(stack_a, "rra\n");
		content->rra--;
	}
	else
		return ;
	run_op(stack_a, stack_b, content, c);
}

void	to_push(t_list **stack_a, t_list **stack_b, int index, char c)
{
	t_list	*tmp;

	if (c == 'a')
		tmp = *stack_b;
	else if (c == 'b')
		tmp = *stack_a;
	while (index--)
		tmp = tmp->next;
	run_op(stack_a, stack_b, tmp->content, c);
	run_op2(stack_a, stack_b, tmp->content, c);
}

void	init_op(t_op *op)
{
	op->to_push = 0;
	op->biggest = 0;
	op->smallest = 0;
	op->big_index = 0;
	op->small_index = 0;
	op->i = 0;
	op->cost = 0;
	op->cheapest = 0;
}

void	optimised_push_b(t_list **stack_a, t_list **stack_b)
{
	t_op	op;

	while (ft_lstsize(*stack_a) != 3)
	{
		init_op(&op);
		calculate_cost_b(*stack_a, *stack_b, &op);
		to_push(stack_a, stack_b, op.to_push, 'b');
	}
}
