/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:18:27 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/07 00:25:51 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "key_defines.h"

# define N_IMG 0xFF

# define WIN_TITLE "Fract'ol"
# define WIN_Y 1080
# define WIN_X 1920

# define MAIN_IMG 0

typedef struct		s_registers
{
	char			err_reg;
	char			st_reg;
	char			imgs_used;
}					t_registers;

typedef struct		s_mlx_img
{
	void			*img;
	int				width;
	int				height;
	char			*encode;
}					t_mlx_img;

typedef struct		s_container
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	int				bpp;
	int				sl;
	int				endian;
	t_registers		regs;
	t_mlx_img		imgs[N_IMG];
}					t_container;

void	init_window(t_container *map);
void	close_prgm(t_container *map, char *msg, short exit);

void	create_img(t_container *map, int win_x, int win_y);
void	close_imgs(t_container *map);
void	put_img_pix(t_container *map, int img_idx, int xPos, int yPos, int col);

void	msg_exit(char *msg);

int		ft_key_read(int keycode, void *param);

int		ft_mouse_read(int button, int x, int y, void *param);

#endif
