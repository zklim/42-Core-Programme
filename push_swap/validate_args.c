/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:10 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 01:24:12 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_list *stack)
{
	t_list	*top;
	t_list	*loop;

	top = stack;
	while (stack)
	{
		loop = top;
		while (loop)
		{
			if (get_index(loop->content) == get_index(stack->content))
			{
				loop = loop->next;
				if (!loop)
					break ;
			}
			else if (get_number(loop->content)
				== get_number(stack->content))
				free_error_exit("Error\n", top);
			loop = loop->next;
		}
		stack = stack->next;
	}
}

void	check_int(char *number)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	if (number[i] == '-' || number[i] == '+')
	{
		sign = -1;
		i++;
	}
	if ((number[i] <= '0' && number[i] >= '9') || !number[i])
		print_error_exit("Error\n");
	while (number[i] == '0')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
	{
		nbr = (nbr * 10) + (number[i] - '0');
		i++;
	}
	if (number[i] != '\0' || (nbr * sign) < -2147483648 || (nbr
			* sign) > 2147483647)
		print_error_exit("Error\n");
}

char	**validate_args(int ac, char **av, int *to_free)
{
	int		i;
	char	**args;

	i = 0;
	if (ac < 2)
		exit(0);
	if (ac == 2)
	{
		if (!ft_strchr(av[1], ' '))
			check_int(av[1]);
		args = ft_split(av[1], ' ');
		*to_free = 1;
	}
	else
		args = av + 1;
	while (args[i])
	{
		check_int(args[i]);
		i++;
	}
	return (args);
}
