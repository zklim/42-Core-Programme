/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:33:19 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/26 18:30:19 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executions/builtins/export2.h"

static char	*add_equal_sign(char *addition)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(addition) + 2));
	if (!new_str)
		return NULL;
	while (addition[i])
	{
		new_str[i] = addition[i];
		i++;
	}
	new_str[i++] = '=';
	new_str[i] = '\0';
	return (new_str);
}

static char	*check_before_dup(char *addition)
{
	int	i;

	i = 0;
	while (addition[i])
	{
		if (addition[i] == '=')
			return (ft_strdup(addition));
		i++;
	}
	return add_equal_sign(addition);
}

void	print_export(char **env)
{
	int	i;
	int	j;
	int	skip;

	i = 0;
	skip = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			if (env[i][j] == '_' && env[i][j + 1] == '=')
			{
				skip = 1;
				break ;
			}
			write(1, &env[i][j], 1);
			j++;
			if (env[i][j - 1] == '=' && !env[i][j])
				write(1, "''", 2);
		}
		if (!skip)
			write(1, "\n", 1);
		i++;
	}
}

void	add_to_env(t_shell *shell, char *addition)
{
	int		i;
	char	**new_env;

	i = ft_arrlen(shell->env);
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return ;
	i = 0;
	while (shell->env[i])
	{
		new_env[i] = shell->env[i];
		i++;
	}
	new_env[i++] = check_before_dup(addition);
	new_env[i] = NULL;
	free(shell->env);
	shell->env = new_env;
}
