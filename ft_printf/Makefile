SRCS		= $(addprefix src/, $(addsuffix .c, ft_printf hexa_ft nub_ft str_char_ft))

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -Iinclude

AR			= ar rc

LIB			= ranlib

RM			= rm -f

LIBFT		= libft.a

$(NAME):	$(LIBFT) $(OBJS)
			$(AR) $(NAME) $(OBJS) libft/$(LIBFT)
			$(LIB) $(NAME)

$(LIBFT):	
			make -C libft/

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