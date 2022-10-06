/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:01:00 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/06 18:26:56 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
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
    d.content = "last";
    ptr = &a;
    ft_lstadd_back(&ptr, &d);
    printf("%s\n", ptr->next->next->next->content);
}*/