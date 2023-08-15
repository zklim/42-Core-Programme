/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:38:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/05 18:19:07 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	write_error(char *str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
}

void	print_error_exit(char *str)
{
	if (!str)
		return ;
	write_error(str);
	exit(1);
}

void	free_error_exit(char *str, t_list *stack)
{
	if (!stack)
		return ;
	write_error(str);
	ft_lstclear(&stack, destroy_content);
	exit(1);
}

void	free_exit(t_list *stack)
{
	if (!stack)
		return ;
	ft_lstclear(&stack, destroy_content);
	exit(1);
}
