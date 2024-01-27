/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:30:35 by zhlim             #+#    #+#             */
/*   Updated: 2024/01/25 19:28:37 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../libft/libft.h"

void	ft_cd(char *path);
void	ft_pwd(void);

#endif