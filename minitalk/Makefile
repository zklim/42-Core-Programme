# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 16:58:02 by zhlim             #+#    #+#              #
#    Updated: 2023/07/01 15:44:34 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= server.c
SRCC		= client.c
SRCSB		= server_bonus.c
SRCCB		= client_bonus.c

OBJS		= server.o
OBJC		= client.o
OBJSB		= server_bonus.o
OBJCB		= client_bonus.o

HEAD		= ./includes/

NAME		= server
NAMEC		= client
NAMEB		= server_bonus
NAMECB		= client_bonus

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

LDFLAGS		= -L.

LDLIBS		= -lft -lftprintf

LIBFT		= libft.a
LIBPRINTF	= libftprintf.a

all:		$(NAME) $(NAMEC)

$(NAME):	$(OBJS) $(LIBFT) $(LIBPRINTF)
			$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(NAMEC):	$(OBJC) $(LIBFT) $(LIBPRINTF)
			$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(LIBFT):	
			make -C libft/
			cp libft/libft.a .

$(LIBPRINTF):
			make -C ft_printf/
			cp ft_printf/libftprintf.a .

bonus:		$(NAMEB) $(NAMECB)

$(NAMEB):	$(OBJSB) $(LIBFT) $(LIBPRINTF)
			$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(NAMECB):	$(OBJCB) $(LIBFT) $(LIBPRINTF)
			$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

clean:
			$(RM) $(OBJS) $(OBJC) $(LIBFT) $(LIBPRINTF) $(OBJSB) $(OBJCB)
			make clean -C ft_printf/
			make clean -C libft/

fclean:		clean
			$(RM) $(NAME) $(NAMEC) $(NAMEB) $(NAMECB)
			make fclean -C ft_printf/
			make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re bonus
