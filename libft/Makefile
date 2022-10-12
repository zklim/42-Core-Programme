
SRCS		= ${filter-out ${SRCSB}, ${wildcard ft*.c}}

SRCSB		= ${wildcard ft_lst*.c}

OBJS		= ${SRCS:.c=.o}

OBJSB		= ${SRCSB:.c=.o}

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -I.

AR			= ar rc

LIB			= ranlib

RM			= rm -f

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIB} ${NAME}

bonus:		${OBJS} ${OBJSB}
			${AR} ${NAME} ${OBJS} ${OBJSB}
			${LIB} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
