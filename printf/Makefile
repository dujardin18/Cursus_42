# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 20:03:50 by fherbine          #+#    #+#              #
#    Updated: 2018/01/02 18:00:42 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES= ./libft/ft_strlen.c ./libft/ft_strchr.c ./libft/ft_atoi.c \
		 ./libft/ft_putchar.c ./libft/ft_putstr.c ./libft/ft_putnbr_base.c \
		 ./libft/ft_nlen_base.c ./libft/ft_strdup.c ./libft/ft_putnbr_z.c \
		 ft_printf.c ft_reading_format.c utilities.c ft_p_c.c ft_p_s.c \
		 ft_p_x.c ft_p_o.c ft_p_p.c ft_ucast_length.c ft_cast_length.c \
		 ft_p_pc.c ft_p_d.c ft_put_nz.c ft_p_u.c ./libft/ft_nlen.c \
		 ft_print_nc.c ft_parser.c
INCLUDES= ./libft/
OBJ = $(SOURCES:.c=.o)
NAME = libftprintf.a
RL = .t

all: $(RL) $(NAME)

$(RL):
	@touch $(RL)
	@clear
	@figlet -f roman -o printf | lolcat
	@echo "\t\t\t\033[4mCOMPILATION\033[0m"
	@echo "\n\tCompilation des fichiers C : \033[0;33;40m[\c"

$(NAME): $(OBJ)
	@echo "]"
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	@echo "=\c"
	@gcc -Wall -Wextra -I $(INCLUDES) -o $@ -c $?

clean :
	@rm -rf $(RL)
	@rm -rf $(OBJ)
	@make -C ./libft/ fclean

fclean : clean
	@rm -rf $(NAME)

re : fclean all
