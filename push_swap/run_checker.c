/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:01:16 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 23:38:47 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_command2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (*line == 'r')
	{
		line++;
		if (*line == 'a')
			single_rotate(stack_a, "ra\n");
		else if (*line == 'b')
			single_rotate(stack_b, "rb\n");
		else if (*line == 'r')
		{
			line++;
			if (*line == 'a')
				single_reverse_rotate(stack_a, "rra\n");
			else if (*line == 'b')
				single_reverse_rotate(stack_b, "rrb\n");
			else if (*line == 'r')
				double_reverse_rotate(stack_a, stack_b, "rrr\n");
			else
				double_rotate(stack_a, stack_b, "rr\n");
		}
	}
}

void	check_command(char *line, t_list **stack_a, t_list **stack_b)
{
	if (*line == 's')
	{
		line++;
		if (*line == 'a')
			single_swap(stack_a, "sa\n");
		else if (*line == 'b')
			single_swap(stack_b, "sb\n");
		else if (*line == 's')
			double_swap(stack_a, stack_b, "ss\n");
	}
	else if (*line == 'p')
	{
		line++;
		if (*line == 'a')
			push(stack_b, stack_a, "pa\n");
		else if (*line == 'b')
			push(stack_a, stack_b, "pb\n");
	}
	else
		check_command2(line, stack_a, stack_b);
}

void	invalidate(char *line)
{
	if (*line != 's' && *line != 'p' && *line != 'r')
		print_error_exit("Error\n");
	line++;
	if (*line != 'a' && *line != 'b' && *line != 'r' && *line != 's')
		print_error_exit("Error\n");
	line++;
	if (*line != '\n' && *line != 'a' && *line != 'b' && *line != 'r')
		print_error_exit("Error\n");
}

void	run_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		invalidate(line);
		check_command(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}
