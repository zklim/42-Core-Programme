/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:07:28 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/25 21:08:43 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECVE_H
# define EXECVE_H

#include <stdio.h>
#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_cmd
{
	char	*path;
	char	**args;
	char	**env;
}	t_cmd;

void	execute_cmd(t_cmd *cmd);

#endif