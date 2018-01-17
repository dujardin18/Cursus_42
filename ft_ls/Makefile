# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 17:04:06 by fherbine          #+#    #+#              #
#    Updated: 2018/01/17 19:42:48 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
INCLUDES = includes
SRC_PATH = sources
OBJ_PATH = $(SRC_PATH)
SRC_NAME = main.c ls_errors.c parser.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LPATH = libft
LFLAGS = -L$(LPATH) -lft
IFLAGS = -I$(INCLUDES)
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: begin $(NAME)

begin:
	make -C $(LPATH)

$(NAME): $(OBJ)
	$(CC) -o $@ $? $(LFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $? -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LPATH) fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all begin clean fclean re
