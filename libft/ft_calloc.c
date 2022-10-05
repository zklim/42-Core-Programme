/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:46:24 by zhlim             #+#    #+#             */
/*   Updated: 2022/10/05 15:00:40 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

/*int   main(void)
{
        int i, * ptr, sum = 0;
        ptr = ft_calloc(10, sizeof(int));
        if (ptr == NULL) {
            printf("Error! memory not allocated.");
            exit(0);
        }
        printf("Sum of the first 10 terms \n");
        for (i = 0; i < 10; ++i) { * (ptr + i) = i;
            sum += * (ptr + i);
        }
        printf("Sum = %d\n", sum);
        free(ptr);
        return (0);
}*/