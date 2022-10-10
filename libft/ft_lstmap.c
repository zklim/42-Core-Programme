/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:20:39 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/10 09:06:56 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*old;

	if (lst && f && del)
	{
		old = lst;
		new = ft_lstnew((f)(lst->content));
		lst = lst->next;
		while (lst)
		{
			ft_lstadd_back(&new, ft_lstnew((f)(lst->content)));
			lst = lst->next;
		}
		ft_lstclear(&old, del);
		return (new);
	}
	return (0);
}

/*void	*f(void *p)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = p;
	while (ptr[i])
	{
		ptr[i] -= 32;
		i++;
	}
	return (ptr);
}

void	del(void *p)
{
	char	*ptr;

	ptr = p;
	while (*ptr)
	{
		*ptr = 0;
		ptr++;
	}
}

int	main(void)
{
	t_list a;
	t_list b;
	t_list c;
	t_list *res;
	char d[] = "hello";
	char e[] = "world";
	char g[] = "last";

	a.next = &b;
	b.next = &c;
	a.content = d;
	b.content = e;
	c.content = g;
	res = ft_lstmap(&a, f, del);
	while (res)
	{
		printf("%s\n", (char *)res->content);
		res = res->next;
	}
}*/