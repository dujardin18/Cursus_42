#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "\033[3;33;40m\t\t>> Making libmlx.a\033[0m"
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@echo "\033[3;35;40m\t>> Cleaning mlx\033[0m"
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
