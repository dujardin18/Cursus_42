/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:18:27 by fherbine          #+#    #+#             */
/*   Updated: 2018/09/19 07:32:51 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "key_defines.h"
# include "mouse_defines.h"
# include <math.h>

# define N_IMG 0xFF

# define WIN_TITLE "Fract'ol"
# define WIN_Y 720
# define WIN_X 1080


# define MAIN_IMG 0

# define JULIA 0
# define MANDEL 1

typedef struct		s_fractal
{
	double			x;
	double			y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			frac_x;
	double			frac_y;
	int				zoom;
	int				col;
	int				win_ofx;
	int				win_ofy;
	int				imax;
}					t_fractal;

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
	t_fractal		frac;
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
	int				wheel_x;
	int				wheel_y;
	int				f_typ;
	t_registers		regs;
	t_mlx_img		imgs[N_IMG];
}					t_container;

void	init_window(t_container *map);
void	close_prgm(t_container *map, char *msg, short exit);

void	create_img(t_container *map, int win_x, int win_y);
void	mlx_update_img(t_container *map, int im_idx);
void	close_imgs(t_container *map);
void	put_img_pix(t_container *map, int img_idx, int xPos, int yPos, int col);

void	msg_exit(char *msg);
void	few_param_ex(void);
void	inv_param_ex(void);

int		ft_key_read(int keycode, void *param);

int		ft_mouse_read(int button, int x, int y, void *param);

void	update_fract_zoom(t_container *map, int im_idx, int add);
void	init_fract(t_container *map, int im_idx, int f_typ);
void	draw_fract(t_container *map, int im_idx, int f_typ);
#endif
