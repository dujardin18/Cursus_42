# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:45:28 by fherbine          #+#    #+#              #
#    Updated: 2017/11/07 15:24:58 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SPATH = srcs/
IPATH = includes/
SRCS = $(SPATH)ft_putchar.c $(SPATH)ft_putstr.c $(SPATH)ft_strcmp.c $(SPATH)ft_strlen.c $(SPATH)ft_swap.c
INCLUDES = $(IPATH)libft.h
NAME = libft.a

all: $(NAME)

$(NAME): compile
	ar rc $(NAME) *.o
	ranlib $(NAME)

compile:
	gcc -I $(INCLUDES) -c $(SRCS)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
