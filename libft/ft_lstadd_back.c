/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:01:00 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/13 15:00:33 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
	}
}

/*int main(void)
{
    t_list  a;
    t_list  b;
    t_list  c;
    t_list  elem;
    t_list  elem1;
    t_list  elem2;
    t_list  elem3;
    t_list  *ptr;

    a.next = &b;
    b.next = &c;
    elem.content = "abc";
    elem1.content = "babc";
    elem2.content = "cabc";
    elem3.content = "dabc";
    elem.next = NULL;
    elem1.next = NULL;
    elem2.next = NULL;
    elem3.next = NULL;
    ptr = &a;
	{
		ft_lstadd_back(&ptr, &elem);
		ft_lstadd_back(&ptr, &elem1);
		ft_lstadd_back(&ptr, &elem2);
		ft_lstadd_back(&ptr, &elem3);
		while (ptr)
		{
			printf("%s\n", ((char *)ptr->content));
			ptr = ptr->next;
		}
	}
}*/