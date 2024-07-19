# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 18:33:57 by yooshima          #+#    #+#              #
#    Updated: 2024/07/19 14:49:00 by yooshima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS		= main.c ope1.c ope2.c sort_three.c sort_big.c set_func.c find_func.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${OBJS} libft/libft.a -o ${NAME}

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS} ${BONUS_OBJS}
			${MAKE} -C libft clean

fclean:		clean
			${RM} ${NAME}
			${RM} libft/libft.a


re:			fclean all

.PHONY:		all clean fclean re