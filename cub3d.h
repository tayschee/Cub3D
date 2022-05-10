/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:11:20 by tbigot            #+#    #+#             */
/*   Updated: 2020/06/11 14:26:00 by tbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include <string.h>
# include <errno.h>
# include "./libft/libft.h"
# include "math.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363

# define ESC 65307
# define TAB 65289

# define RED 16711680
# define GREEN 2088960
# define BLUE 255
# define WHITE 16777215
# define BLACK 0
# define YELLOW 16776960
# define GREY 13882323
# define PURPLE 8388736
# define TGREY 3372220415

# define DIMENSION 1
# define EYE 0.5
# define DIMENSION_PLAYER 0.2
# define DIMENSION_SPRITE 1
# define RATIO 3

# define SPEED 0.1
# define ROTATE_SPEED 0.1308

typedef	struct		s_wdw
{
	void			*ptr;
	void			*win;
	int				height;
	int				width;
	int				bpp;
	int				size_line;
	int				end;
	void			*img_ptr;
	char			*img_data;
	void			*img_mn_ptr;
	char			*img_mn_data;
	int				x;
	int				y;
	int				dim_mini;
	int				print_map;
	int				sl_no;
	int				sl_so;
	int				sl_we;
	int				sl_ea;
}					t_wdw;

typedef struct		s_map
{
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
	char			*noc;
	char			*soc;
	char			*wec;
	char			*eac;
	int				fc;
	int				cc;
	char			**map;
	int				dim_no[2];
	int				dim_so[2];
	int				dim_we[2];
	int				dim_ea[2];
}					t_map;

typedef struct		s_wall
{
	double			x;
	double			y;
	double			xbis;
	double			ybis;
	double			hyp;
	int				size_x;
	int				size_y;
	int				horiz;
	double			size;
	char			*text;
	int				size_line;
	int				width;
	int				height;
}					t_wall;

typedef	struct		s_char
{
	double			view;
	double			vvx;
	double			vvy;
	double			vx;
	double			vy;
	double			x;
	double			y;
	float			dim;
	double			ray;
}					t_char;

typedef struct		s_sprt
{
	void			*s;
	char			*sc;
	int				sl_s;
	int				dim_s[2];
	int				beg;
	double			*wray;
	int				left;
}					t_sprt;

typedef struct		s_vsprt
{
	double			x;
	double			y;
	double			dist_x;
	double			dist_y;
	char			c;
	double			dist;
	double			angle;
	struct s_vsprt	*next;

}					t_vsprt;

typedef struct		s_all
{
	t_map			tmap;
	t_char			tchar;
	t_wdw			twdw;
	t_wall			twall;
	t_sprt			tsprt;
	t_vsprt			*tvsprt;
	char			*line;
	int				mode;
}					t_all;

int					main(int c, char **v);

t_all				*initialise_struct_all(int mode);
void				free_all(t_all *all, char *msg, int i, int line);

void				parsing(char *file_name, t_all *data);
void				for_parsing_text(t_all *data);
void				verifmap(t_all *data);
void				verif_pars(t_all *data);
void				check_void(t_all *data, int i, int j);
void				add_space(t_all *data);
void				define_dimension(t_all *data, int map_w, int map_h);

void				window(char *map, t_all *data);

int					raycasting(t_all *data);
void				view(t_all *data, double v, int *color);

void				check_horizontal(t_all *data, double x, double y, double v);
void				check_vertical(t_all *data, double x, double y, double v);

void				sprite(t_all *data, int posx, int posy, double v);
void				closest_sprite_to_further(t_all *data);
void				map_without_x(t_all *data);
void				free_tvsprt(t_all *data);

void				print_sprite(t_all *data);

void				print3d(t_all *data, int x, double angle);
double				pos_text(t_all *data);
int					apply_text(t_all *data, double proj_wall,
					double start_text, int y);

int					minimap(t_all *data, double add, double *ray, int *color);

void				screen(t_all *data);
void				bit_map_pixel_data(int fd, t_all *data, char *txt);

char				what_case(t_all *data, double x, double y);
int					check_player_position(t_all *data, double vx, double vy);

double				pythagore(double c1, double c2);
int					*long_to_orgb(long int color);
double				trigo_pi(double angle);
int					verifchar(char c, char *valid);

#endif
