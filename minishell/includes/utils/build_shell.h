/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:24:53 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/25 23:20:40 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_SHELL_H
# define BUILD_SHELL_H

# include "../libft/libft.h"

typedef struct s_shell
{
	char	**env;
}	t_shell;

int		ft_arrlen(char **arr);
char	**build_env(char **env);

#endif