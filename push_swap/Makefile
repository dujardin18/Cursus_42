# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 17:00:23 by fherbine          #+#    #+#              #
#    Updated: 2018/01/09 17:19:41 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
CHK_SRC_PATH = ch_sources
CHK_HEAD_PATH = ch_includes
P_S_SRC_PATH = ps_sources
P_S_HEAD_PATH = ps_includes
CHK_DEBUG_PATH = $(CHK_SRC_PATH)/debug
P_S_DEBUG_PATH = $(P_S_SRC_PATH)/debug
CHK_SRC_NAME = main.c checker.c pile.c utilities.c parser.c instructions.c actions.c
CHK_OBJ_NAME = $(CHK_SRC_NAME:.c=.o)
P_S_SRC_NAME = main.c push_swap.c
P_S_OBJ_NAME = $(P_S_SRC_NAME:.c=.o)
CHK_SRC = $(addprefix $(CHK_SRC_PATH)/,$(CHK_SRC_NAME))
P_S_SRC = $(addprefix $(P_S_SRC_PATH)/,$(P_S_SRC_NAME))
CHK_OBJ = $(addprefix $(CHK_DEBUG_PATH)/,$(CHK_OBJ_NAME))
P_S_OBJ = $(addprefix $(P_S_DEBUG_PATH)/,$(P_S_OBJ_NAME))
CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/
LFLAGS = -L$(LIBFT) -lft

all: begin $(CHECKER) $(PUSH_SWAP)

begin:
	@clear
	@figlet -f roman -c "Push Swap" | lolcat
	@echo "\n\n\t\t\t\t>>> COMPILATION <<<\n> Libft :\t\033[0;33;40m[\c"
	@make -C $(LIBFT)
	@echo "> Checker :\t\033[0;33;40m[\c"

$(CHECKER): $(CHK_OBJ)
	@$(CC) -o $@ $? $(LFLAGS)
	@echo "]\033[0m \033[0;32;40m--> Done.\033[0m"
	@echo "> Push_Swap :\t\033[0;33;40m[\c"

$(PUSH_SWAP): $(P_S_OBJ)
	@$(CC) -o $@ $? $(LFLAGS)
	@echo "]\033[0m \033[0;32;40m--> Done.\033[0m\n"
	@cat others/usage

$(CHK_DEBUG_PATH)/%.o : $(CHK_SRC_PATH)/%.c
	@echo "=\c"
	@$(CC) $(CFLAGS) -I$(CHK_HEAD_PATH) -c $? -o $@

$(P_S_DEBUG_PATH)/%.o : $(P_S_SRC_PATH)/%.c
	@echo "=\c"
	@$(CC) $(CFLAGS) -I$(P_S_HEAD_PATH) -c $? -o $@

clean:
	@echo "\033[0;31;40m>> CLEAN <<\033[0m"
	@rm -rf $(CHK_OBJ) $(P_S_OBJ)
	@make -C $(LIBFT) fclean

fclean: clean
	@rm -rf $(CHECKER) $(PUSH_SWAP)
	@echo "\033[0;32;40mDone.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re, begin
