/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:55:50 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/06 16:59:17 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = ft_strdup(content);
	new_node->next = NULL;
	return (new_node);
}

/*int main(void)
{
    t_list *a;
    
    a = ft_lstnew("hello");
    printf("%s\n%p\n", a->content, a->next);
}*/