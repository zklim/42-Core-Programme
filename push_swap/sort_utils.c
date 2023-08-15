/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:26:45 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 01:29:28 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_number(t_content *content)
{
	return (content->number);
}

int	get_index(t_content *content)
{
	return (content->index);
}

int	check_sorted(t_list *stack_a)
{
	int	a;
	int	b;

	while (stack_a)
	{
		if (stack_a->next)
		{
			a = get_number(stack_a->content);
			b = get_number(stack_a->next->content);
			if (a > b)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	smallest_pos(t_list *stack, int size)
{
	t_op	op;

	init_op(&op);
	op.smallest = get_number(stack->content);
	op.small_index = op.i;
	while (stack)
	{
		if (get_number(stack->content) < op.smallest)
		{
			op.smallest = get_number(stack->content);
			op.small_index = op.i;
		}
		op.i++;
		stack = stack->next;
	}
	if (op.small_index < (size / 2) + 1)
		return (1);
	else
		return (0);
}
