/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:51:18 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/26 17:28:54 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executions/builtins/echo.h"

static char	*get_env_key(char *env)
{
	char	*key;
	int		i;

	i = 0;
	while (env[i] != '=')
		i++;
	key = (char *)malloc(sizeof(char) * i + 1);
	if (!key)
		return NULL;
	else
	{
		i = 0;
		while (env[i] != '=')
		{
			key[i] = env[i];
			i++;
		}
		key[i] = '\0';
		return (key);
	}
}

static void	ft_env_value(char *env)
{
	int		i;

	i = 0;
	while (env[i] != '=')
		i++;
	ft_putstr_fd(env + i + 1, 1);
}


// IMPORTANT: Print exit code yet to be implemented
void	ft_echo(char *str, int flag_n, char **env)
{
	char	*key;

	if (!str || !*str)
		return;
	if (*str == '$')
	{
		if (*(str + 1) == '?')
			write(1, "PRINT_EXIT_CODE", 15);
		else
		{
			while (*env)
			{
				key = get_env_key(*env);
				if (!ft_strncmp(key, str + 1, ft_strlen(key)))
				{
					ft_env_value(*env);
					free(key);
					break;
				}
				free(key);
				env = env + 1;
			}
		}
	}
	else
		ft_putstr_fd(str, 1);
	if (!flag_n)
		write(1, "\n", 1);
	return;
}