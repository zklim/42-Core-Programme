/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:04:17 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/23 15:52:16 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executions/execve.h"

void	execute_cmd(t_cmd *cmd) {
	if (execve(cmd->path, cmd->args, cmd->env) == -1)
	{
		perror(strerror(errno));
		exit(errno);
	}
}
