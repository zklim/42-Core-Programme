# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 16:30:48 by zhlim             #+#    #+#              #
#    Updated: 2023/08/11 11:34:31 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(addsuffix .c, push_swap validate_args build_and_destroy_stacks error_handling operations run_operations sort \
					 optimised_push_a optimised_push_b calculate_cost_a calculate_cost_b calculate_cost2 calculate_rev_a \
					 calculate_rev_b calculate_utils sort_utils)
SRCB			= $(addsuffix .c, checker validate_args build_and_destroy_stacks error_handling operations run_operations sort \
					 optimised_push_a optimised_push_b calculate_cost_a calculate_cost_b calculate_cost2 calculate_rev_a \
					 calculate_rev_b calculate_utils sort_utils run_checker) \
					 $(addprefix libft/get_next_line/, $(addsuffix .c, get_next_line get_next_line_utils))

OBJS			= $(patsubst %.c, %.o, $(SRCS))
OBJB			= $(patsubst %.c, %.o, $(SRCB))

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
# -g
# -fsanitize=address

RM				= rm -f

INCLUDES		= -I. -Ilibft -Ilibft/ft_printf/include/ -Ilibft/get_next_line

NAME			= push_swap
NAMEB			= checker

LIBFT			= libft/libft.a
LIBFTFLAGS		= -Llibft/ -lft
LIBPRINTF		= libft/ft_printf/libftprintf.a
LIBPRINTFFLAGS	= -Llibft/ft_printf -lftprintf

%.o:			%.c
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ $(LIBFTFLAGS) $(LIBPRINTFFLAGS) -o $@

$(NAMEB):		$(OBJB)
				$(CC) $(CFLAGS) $^ $(LIBFTFLAGS) $(LIBPRINTFFLAGS) -o $@
				
all:			$(NAME) bonus

bonus:			$(NAMEB)

$(OBJS):		$(LIBFT) $(LIBPRINTF)
$(OBJB):		$(LIBFT) $(LIBPRINTF)

$(LIBFT):		
				make bonus -C libft/

$(LIBPRINTF):	
				make -C libft/ft_printf/

clean:		
				$(RM) $(OBJS) $(OBJB)
				make clean -C libft/
				make clean -C libft/ft_printf/
				
fclean:			clean
				$(RM) $(NAME) $(NAMEB)
				make fclean -C libft/
				make fclean -C libft/ft_printf/

re:				fclean all

.PHONY:			all clean fclean re bonus