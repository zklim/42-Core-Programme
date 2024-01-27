/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:18:08 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/26 20:34:59 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executions/builtins/unset.h"

static int	ft_strlen_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	return (i);
}

static char	**new_env(char ***env, int target)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = (char **)malloc(sizeof(char *) * ft_arrlen(*env));
	if (!new_env)
		return NULL;
	while ((*env)[i])
	{
		if (i == target)
			free((*env)[i]);
		else
			new_env[j++] = (*env)[i];
		i++;
	}
	new_env[j] = NULL;
	free(*env);
	return new_env;
}

void		ft_unset(t_shell *shell, char *str)
{
	int	i;
	int	len;
	int	len_2;

	i = 0;
	len = ft_strlen(str);
	while (shell->env[i])
	{
		len_2 = ft_strlen_equal(shell->env[i]);
		if (len == len_2)
		{
			if (ft_strncmp(shell->env[i], str, len) == 0)
				shell->env = new_env(&shell->env, i);
		}
		i++;
	}
	
}