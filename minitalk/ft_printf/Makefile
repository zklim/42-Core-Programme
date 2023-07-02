# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 16:26:40 by zhlim             #+#    #+#              #
#    Updated: 2023/06/29 16:26:41 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(addprefix src/, $(addsuffix .c, ft_printf hexa_ft nub_ft str_char_ft))

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -Iinclude

AR			= ar rc

LIB			= ranlib

RM			= rm -f

$(NAME):	$(OBJS) 
			$(AR) $(NAME) $(OBJS)
			$(LIB) $(NAME)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)
			make clean -C libft/

fclean:		clean
			$(RM) $(NAME)
			make fclean -C libft/

re:			fclean all
			make re -C libft/

.PHONY:		all clean fclean re