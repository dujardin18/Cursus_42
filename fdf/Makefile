# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 16:59:42 by fherbine          #+#    #+#              #
#    Updated: 2017/12/22 13:56:50 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ./sources/main.c ./sources/ft_fdf.c ./sources/parser.c ./sources/utilities.c ./sources/ft_draw.c ./sources/ft_draw_aux.c
OBJS = $(SOURCES:.c=.o)
NAME = fdf
INCLUDES = ./includes/
FLAGS= -Wall -Wextra 

all: rl $(NAME)

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft
	@echo "\n\033[0;32;40m >>>>>>>>>>>>>>>>>>>>>>>>> DONE <<<<<<<<<<<<<<<<<<<<<<<<<<<< \033[0m\n"
	@clear
	@figlet -f roman -o Fil de Fer | lolcat
	@echo "*-------------------* \033[1;33;40mUSAGE\033[0m *---------------------*"
	@echo "|                                                 |"
	@echo "| > ./fdf map_file.fdf [x_size] [y_size]          |"
	@echo "|                                                 |"
	@echo "| \033[1;37;40mKEY_CONTROLS\033[0m :                                  |"
	@echo "|                                                 |"
	@echo "|                \033[4;35;40m~ Controls ~\033[0m                     |"
	@echo "|  \033[1;37;40m[ESC]\033[0m : Quitter la map  \033[1;37;40m[4]\033[0m : Dep. Gauche      |"
	@echo "|  \033[1;37;40m[+]\033[0m : Zoom +            \033[1;37;40m[6]\033[0m : Dep. Droite      |"
	@echo "|  \033[1;37;40m[-]\033[0m : Zoom -            \033[1;37;40m[8]\033[0m : Dep. Haut        |"
	@echo "|  \033[1;37;40m[7]\033[0m : Rotation gauche   \033[1;37;40m[2]\033[0m : Dep. Bas         |"
	@echo "|  \033[1;37;40m[9]\033[0m : Rotation Droite                          |"
	@echo "|  \033[1;37;40m[1]\033[0m : Effacement du relief (visuel) /          |"
	@echo "|        rotation Bas                             |"
	@echo "|  \033[1;37;40m[3]\033[0m : Exagerer le relief / rotation haut       |"
	@echo "|                                                 |"
	@echo "|                \033[4;35;40m~ Couleurs ~\033[0m                     |"
	@echo "|  \033[1;37;40m[Q]\033[0m : monochrome        \033[1;37;40m[S]\033[0m : Couleur sable    |"
	@echo "|  \033[1;37;40m[A]\033[0m : aleatoire                                |"
	@echo "|                                                 |"
	@echo "*-------------------------------------------------*\n"

rl:
	@echo "\033[0;32;40m>> Compiling all\033[0m"
	@echo "\033[3;36;40m\t>> Compiling libft\033[0m"
	@make -C ./libft/  all
	@echo "\033[3;36;40m\t>> Compiling mlx\033[0m"
	@make -C ./minilibx_macos/ all

%.o: %.c 
	@gcc $(FLAGS) -I $(INCLUDES) -c $? -o $@

clean:
	@echo "\033[0;31;40m>> Cleaning All\033[0m"
	@make -C ./libft/ fclean
	@make -C ./minilibx_macos/ clean
	@echo "\033[3;35;40m\t>> Cleaning fdf\033[0m"
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@echo ""

re: fclean all
