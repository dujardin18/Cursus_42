# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:03:11 by fherbine          #+#    #+#              #
#    Updated: 2017/12/30 13:03:32 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	   ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	   ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_bzero.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memset.c ft_memalloc.c ft_memdel.c ft_strclr.c ft_strdel.c \
	   ft_striter.c ft_strnew.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_itoa.c ft_strsplit.c ft_putchar.c ft_putstr.c ft_putendl.c \
	   ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	   ft_lstiter.c ft_lstmap.c ft_swap.c ft_str_is_printable.c \
	   ft_putnbr_base.c get_next_line.c ft_absol.c ft_nlen_base.c ft_nlen.c \
	   ft_putnbr_z.c
NAME = libft.a
INCLUDE = libft.h
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): rl $(OBJ)
	@echo "]\033[0m\n\033[3;33;40m\t\t>> Making libft.a\033[0m"
	@ar rcs $(NAME) $(OBJ)

rl: 
	@echo "\033[0;33;40m\t\t>> Compiling all functions[\c"

%.o: %.c
	@echo "=\c"
	@gcc $(FLAGS) -I $(INCLUDE) -c $? -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[3;35;40m\t>> Cleaning libft\033[0m"
	@rm -rf $(NAME)

re: fclean all
