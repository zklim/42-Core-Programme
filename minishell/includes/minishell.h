/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:36:22 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/26 19:34:10 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "executions/execve.h"
# include "executions/builtins/echo.h"
# include "executions/builtins/pwd.h"
# include "executions/builtins/cd.h"
# include "executions/builtins/export.h"
# include "executions/builtins/env.h"
# include "executions/builtins/unset.h"
# include "utils/build_shell.h"

#endif