/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:10:02 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/10 08:47:15 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int main(void)
{
    t_list *a;
    t_list  b;
    t_list  c;

    c.content = "Hello";
    c.next = 0;
    b.content = "World";
    b.next = 0;
    a = &c;
    printf("First List: %p, %p, %s\n", a, a->next, a->content);
    printf("Address New: %p\n", &b);
    ft_lstadd_front(&a, &b);
    printf("First List: %p, %p, %s\n", a, a->next, a->content);
    printf("Seecond List: %p, %p, %s\n", a->next, a->next->next,
		a->next->content);
}*/