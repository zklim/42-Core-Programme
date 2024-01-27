# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 16:28:26 by zhlim             #+#    #+#              #
#    Updated: 2023/09/13 15:39:51 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(addsuffix .c, philo_bonus routine ft_fork create_philo utils utils2 monitor)

OBJS			= $(patsubst %.c, %.o, $(SRCS))

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
# -fsanitize=thread

RM				= rm -f

INCLUDES		= -I.

NAME			= philo_bonus

%.o:			%.c
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $@
				
all:			$(NAME)

clean:		
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re