#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/25 10:49:07 by ytailor           #+#    #+#              #
#    Updated: 2013/12/27 12:34:36 by ytailor          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

SRC = push_swap.c main.c ft_sort.c element.c rotate.c

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAG) $(SRC) -o $(NAME) libft/libft.a

fclean:
	make fclean -C libft/
	/bin/rm $(NAME)

re: fclean all
