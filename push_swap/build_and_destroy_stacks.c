/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_and_destroy_stacks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:35:28 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 16:38:29 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_content(void *content)
{
	if (!content)
		return ;
	free(content);
}

// index starts from 1
t_content	*build_content(char *num, int index)
{
	t_content	*content;

	content = (t_content *)malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->number = ft_atoi(num);
	content->index = index;
	content->cost = 0;
	content->ra = 0;
	content->rb = 0;
	content->rr = 0;
	content->rra = 0;
	content->rrb = 0;
	content->rrr = 0;
	return (content);
}

t_list	*build_stack_a(char **args)
{
	t_list		*stack_a;
	t_list		*tmp;
	t_content	*content;
	int			i;

	i = 0;
	while (args[i])
	{
		content = build_content(args[i], i);
		if (!content)
			free_exit(stack_a);
		tmp = ft_lstnew(content);
		if (i == 0)
			stack_a = tmp;
		if (!content || !tmp)
			free_error_exit("Error\n", stack_a);
		if (i != 0)
			ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	return (stack_a);
}
