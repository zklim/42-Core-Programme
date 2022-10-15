/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:27:21 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/14 22:39:48 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		(del)(lst->content);
		free(lst);
	}
}

/*void	del(void *p)
{
	char	*ptr;

	ptr = p;
	while (*ptr)
	{
		*ptr = '1';
		ptr++;
	}
}

int	main(void)
{
	t_list a;
	char	b[] = "hello";

	a.content = b;

	printf("%s\n", (char *)a.content);
	ft_lstdelone(&a, del);
	printf("%s\n", (char *)a.content);
}*/