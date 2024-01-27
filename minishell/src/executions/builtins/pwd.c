/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:04:24 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/25 17:11:49 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executions/builtins/pwd.h"

void	ft_pwd(void)
{
	char	*cwd;
	
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return ;
	printf("%s\n", cwd);
	free(cwd);
}