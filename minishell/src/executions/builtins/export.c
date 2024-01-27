/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:09:07 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/26 18:30:48 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executions/builtins/export.h"

static char	**create_subarrays(char **arr, int l, int r)
{
	int		i;
	char	**subarray;

	i = 0;
	subarray = (char **)malloc(sizeof(char *) * (r + 1));
	if (!subarray)
		return NULL;
	while (i < r)
	{
		subarray[i] = arr[l + i];
		i++;
	}
	subarray[i] = NULL;
	return (subarray);
}

static void	merge(char **arr, int l, int m, int r) 
{ 
    int		i;
	int		j;
	int		k; 
    char	**L;
	char	**R; 

    i = 0;
    j = 0;
    k = l;
	L = create_subarrays(arr, l, m - l + 1);
	R = create_subarrays(arr, m + 1, r - m);
    while (i < m - l + 1 && j < r - m) 
    { 
        if (R[j] == NULL || *L[i] <= *R[j]) 
            arr[k++] = L[i++]; 
        else
            arr[k++] = R[j++]; 
    }
    while (i < m - l + 1) 
        arr[k++] = L[i++]; 
    while (j < r - m) 
        arr[k++] = R[j++]; 
	free(L);
	free(R);
} 

static void	merge_sort(char **arr, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l + (r - l) / 2; 
        merge_sort(arr, l, m); 
        merge_sort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
}

static void	sort_and_print(char **env, int size)
{
	merge_sort(env, 0, size);
	print_export(env);
}

void		ft_export(t_shell *shell, char *addition)
{
	if (addition == NULL)
		sort_and_print(shell->env, ft_arrlen(shell->env));
	else
		add_to_env(shell, addition);
}