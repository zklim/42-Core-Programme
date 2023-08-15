/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:16:11 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/05 14:35:10 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_swap(t_list **stack, char *str)
{
	swap(stack);
	ft_printf(str);
}

void	double_swap(t_list **stack_a, t_list **stack_b, char *str)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf(str);
}

void	single_rotate(t_list **stack, char *str)
{
	rotate(stack);
	ft_printf(str);
}

void	double_rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf(str);
}

void	single_reverse_rotate(t_list **stack, char *str)
{
	reverse_rotate(stack);
	ft_printf(str);
}
