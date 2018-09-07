# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 19:17:37 by fherbine          #+#    #+#              #
#    Updated: 2018/09/07 08:04:03 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
IPATH =  includes
SPATH = sources
LFTPATH = libft
MLXPATH =  minilibx_macos
OPATH = $(SPATH)/debug
SNAMES = main.c mlx_routine.c errors.c getkeyboard.c mlx_imgs.c mouse.c frac_utils.c
ONAMES = $(SNAMES:.c=.o)
SRCS = $(addprefix $(SPATH)/,$(SNAMES))
OBJS = $(addprefix $(OPATH)/,$(ONAMES))
CFLAGS = -Wall -Wextra
IFLAGS = -I$(IPATH)
LFTFLAGS = -L$(LFTPATH) -lft
MLXFLAGS = -L$(MLXPATH) -lmlx -framework OpenGL -framework AppKit
CC = gcc

all: $(NAME)

$(OPATH):
	@mkdir $(OPATH)

$(NAME): $(OPATH) $(OBJS)
	@make -C $(LFTPATH)
	@make -C $(MLXPATH)
	$(CC) -o $@ $(OBJS) $(MLXFLAGS) $(LFTFLAGS)

$(OPATH)/%.o: $(SPATH)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $? -o $@

clean:
	@make -C $(LFTPATH) fclean
	@make -C $(MLXPATH) clean
	@rm -rf $(OPATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

