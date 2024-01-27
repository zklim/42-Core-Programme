# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 16:28:26 by zhlim             #+#    #+#              #
#    Updated: 2023/09/13 15:29:06 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(addsuffix .c, philo create_philo ft_free create_threads create_forks utils utils2)

OBJS			= $(patsubst %.c, %.o, $(SRCS))

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
# -g -fsanitize=thread

RM				= rm -f

INCLUDES		= -I.

NAME			= philo

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