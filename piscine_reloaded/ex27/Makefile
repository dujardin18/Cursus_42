# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 13:59:46 by fherbine          #+#    #+#              #
#    Updated: 2017/11/07 14:51:55 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c ft_writing.c ft_reading.c
HEADER = ft_header.h
NAME = ft_display_file

all: $(NAME)

$(NAME): compile
	gcc -o $(NAME) *.o

compile:
	gcc -c $(SOURCES) -I $(HEADER)

clean: 
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
