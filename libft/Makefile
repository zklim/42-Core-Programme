
SRCS		= ${filter-out ${SRCSB}, ${wildcard ft*.c}}

SRCSB		= ${wildcard ft_lst*.c}

OBJS		= ${SRCS:.c=.o}

OBJSB		= ${SRCSB:.c=.o}

NAME		= libft.a

AR			= ar rc

LIB			= ranlib

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I. $< -o ${<:.c=.o}

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
