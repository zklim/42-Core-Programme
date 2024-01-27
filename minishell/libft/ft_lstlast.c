/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:56:09 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/13 14:53:24 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int main(void)
{
    t_list  a;
    t_list  b;
    t_list  c;
    t_list  *d;

    a.next = &b;
    b.next = &c;
    c.content = "last";
    d = ft_lstlast(&a);
    printf("%s\n", d->content);
}*/