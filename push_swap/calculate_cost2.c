/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:10:49 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 16:57:08 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost_a2(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	content_b;

	op->i = 0;
	while ((op->i < op->cheapest && stack_b) || op->i == 0)
	{
		copy_content(stack_b->content, &content_b, 1);
		content_b.rb = op->i;
		op->cost = get_revcost_a(&content_b, stack_a, op);
		check_double(&content_b, op);
		if (op->cost < op->cheapest)
		{
			op->cheapest = op->cost;
			op->to_push = op->i;
			copy_content(&content_b, stack_b->content, 0);
		}
		op->i++;
		stack_b = stack_b->next;
	}
}

void	calculate_cost_b2(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	content_a;

	op->i = 0;
	while ((op->i < op->cheapest && stack_a) || op->i == 0)
	{
		copy_content(stack_a->content, &content_a, 1);
		content_a.ra = op->i;
		op->cost = get_revcost_b(&content_a, stack_b, op);
		check_double(&content_a, op);
		if (op->cost < op->cheapest)
		{
			op->cheapest = op->cost;
			op->to_push = op->i;
			copy_content(&content_a, stack_a->content, 0);
		}
		op->i++;
		stack_a = stack_a->next;
	}
}
