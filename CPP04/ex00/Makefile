# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 15:01:34 by zhlim             #+#    #+#              #
#    Updated: 2023/10/30 16:36:38 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(addsuffix .cpp, main Animal Dog Cat WrongAnimal WrongCat)

OBJS		= $(SRCS:.cpp=.o)

CC			= c++

CFLAGS		= -Wall -Werror -Wextra -std=c++98

NAME		= main

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

all:		$(NAME)
			
clean:		
			$(RM) $(OBJS)
				
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re