# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 17:04:06 by fherbine          #+#    #+#              #
#    Updated: 2018/02/05 19:53:15 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
INCLUDES = includes
SRC_PATH = sources
OBJ_PATH = $(SRC_PATH)/debug
SRC_NAME = main.c ls_errors.c parser.c list.c operations.c perms.c rparser.c rlist.c ls_sort.c display.c ft_ls.c max_free.c display_aux.c get_inf.c max.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LPATH = libft
LFLAGS = -L$(LPATH) -lft
IFLAGS = -I$(INCLUDES)
CFLAGS = -Wall -Wextra 
CC = gcc

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@clear
	@figlet -c -f roman "ft_ls" | lolcat
	@mkdir $@
	@echo "\t\t\t>>> \033[1mCOMPILING FT_LS\033[0m <<<\n"
	@echo ">>> Making Libft : \033[0;33;40m[\c"
	@make -C $(LPATH)
	@echo ">>> Making ft_ls : \033[0;33;40m[\c"

$(NAME): $(OBJ)
	@$(CC) -o $@ $? $(LFLAGS)
	@echo "]\033[0m --> \033[1;32;40m[Done]\033[0m\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "=\c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $? -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LPATH) fclean

fclean: clean
	@echo "\033[0;31;40mCLEANING ALL"
	@rm -rf $(NAME)
	@echo "Done.\033[0m"

re: fclean all

.PHONY: all clean fclean re
