SRCS		= $(addprefix src/,ft_printf.c hexa_ft.c nub_ft.c str_char_ft.c)

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

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re