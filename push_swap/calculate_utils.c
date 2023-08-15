/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:59:01 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 17:01:35 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_content *content, t_op *op)
{
	while (content->rb && content->ra)
	{
		content->rb--;
		content->ra--;
		content->rr++;
	}
	while (content->rrb && content->rra)
	{
		content->rrb--;
		content->rra--;
		content->rrr++;
	}
	op->cost = content->rb + content->ra + content->rr
		+ content->rrb + content->rra + content->rrr;
}

void	copy_content(t_content *src, t_content *dst, int clear)
{
	dst->cost = src->cost;
	dst->index = src->index;
	dst->number = src->number;
	if (clear)
		clear_op(dst);
	else
	{
		dst->ra = src->ra;
		dst->rb = src->rb;
		dst->rr = src->rr;
		dst->rra = src->rra;
		dst->rrb = src->rrb;
		dst->rrr = src->rrr;
	}
}
