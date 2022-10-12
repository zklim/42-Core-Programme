/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:01:00 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/12 15:43:29 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			while ((*lst)->next && new)
				*lst = (*lst)->next;
			(*lst)->next = new;
		}
	}
}

/*int main(void)
{
    t_list  a;
    t_list  b;
    t_list  c;
    t_list  d;
    t_list  *ptr;

    a.next = &b;
    b.next = &c;
    d.content = "addlast";
    ptr = &a;
    printf("%p\n", a.next->next->next);
    ft_lstadd_back(&ptr, &d);
    printf("%s\n", (char *)a.next->next->next->content);
}*/