/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:56 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 17:09:55 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	nbr;

	if (ft_lstsize(*stack_a) != 3)
		return ;
	while (!check_sorted(*stack_a))
	{
		nbr = get_number((*stack_a)->content);
		if (nbr > get_number(ft_lstlast(*stack_a)->content))
			single_rotate(stack_a, "ra\n");
		else if (nbr > get_number((*stack_a)->next->content))
			single_swap(stack_a, "sa\n");
		else
			single_rotate(stack_a, "ra\n");
	}
}

void	set_head(t_list **stack_a, int size)
{
	if (smallest_pos(*stack_a, size))
	{
		while (!check_sorted(*stack_a))
			single_rotate(stack_a, "ra\n");
	}
	else
	{
		while (!check_sorted(*stack_a))
			single_reverse_rotate(stack_a, "rra\n");
	}
}

void	sort_advance(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 4)
		push(stack_a, stack_b, "pb\n");
	else
	{
		push(stack_a, stack_b, "pb\n");
		push(stack_a, stack_b, "pb\n");
		optimised_push_b(stack_a, stack_b);
	}
	sort_3(stack_a);
	optimised_push_a(stack_a, stack_b);
	set_head(stack_a, size);
}
