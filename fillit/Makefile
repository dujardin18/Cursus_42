# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 18:54:25 by fherbine          #+#    #+#              #
#    Updated: 2017/11/26 21:39:41 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = utilities.c parser.c fillit.c main.c add_tab.c
LIB = babab.h
LIBFT = libft/libft.a
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	gcc -o $@ $(OBJ) -L./libft/ -lft

$(LIBFT):
	make -C ./libft/ re

%.o : %.c
	gcc -I ./libft/  -c $? -Wall -Werror -Wextra

clean :
	make -C ./libft/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re : fclean all
