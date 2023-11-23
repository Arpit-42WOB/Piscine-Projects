# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 21:43:34 by amehrotr          #+#    #+#              #
#    Updated: 2023/02/16 22:10:02 by amehrotr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= srsc/ft_putchar.c srsc/ft_swap.c srsc/ft_putstr.c srsc/ft_strlen.c srsc/ft_strcmp.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
LIBC	= ar rc
LIBR	= ranlib
RM		= rm -f

.c.o:
		cc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
