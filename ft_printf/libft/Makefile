# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 15:02:29 by zhlim             #+#    #+#              #
#    Updated: 2023/07/02 17:02:14 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
			 	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
				ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
				ft_substr.c ft_tolower.c ft_toupper.c

SRCSB		=  ft_lstsize.c ft_lstnew.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c\
				ft_lstdelone.c ft_lstiter.c ft_lstmap.c

OBJS		= $(SRCS:.c=.o)

OBJSB		= $(SRCSB:.c=.o)

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -I.

AR			= ar rc

LIB			= ranlib

RM			= rm -f

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(LIB) $(NAME)

bonus:		$(OBJS) $(OBJSB)
			$(AR) $(NAME) $(OBJS) $(OBJSB)
			$(LIB) $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJSB)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
