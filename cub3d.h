/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:27:04 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/02 11:52:03 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUB3D
// # define g_cub.w 670
// # define g_cub.h 480
# define PLAYERR 2
# define WALKSTEP 3
# define FOV_ANGLE 60 * (M_PI / 180)

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"


void    *g_win_ptr;
void    *g_img;
void	*param;
int     g_num_rays;
int     g_keys[7];
void	*g_img_3d;
int		g_newline;
char	*g_config;
int		g_tile;
int		g_tile_p;
int		g_n_sp;
int		g_floor_color;
int		g_ceil_color;
int		g_screenshot;
int		g_index_sp;
int		g_n_sp;

typedef struct s_player
{
    float   x;
    float   y;
    int     turnDirection;
    int     walkDirection;
    float   moveSpeed;
    float   rotationAngle;
    float   rotationSpeed;
    float   moveStep;
    float   oldx;
    float   oldy;
	float	fov;

}           t_player;

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_wall_hit
{
	double		x;
	double		y;
}				t_wall_hit;

typedef struct  s_rays
{
    double		angle;
    double		dist;
	int			was_hit_vertical; // hit == 1 is vert and === 0 is heris
	t_wall_hit	wall_hit;
	int			is_down;
	int			is_up;
	int			is_right;
	int			is_left;
    
}           t_rays;
typedef struct	s_ray
{
	double		angle;
	int			is_down;
	int			is_up;
	int			is_right;
	int			is_left;
}				t_ray;

typedef struct	s_cast
{
	double		xinterept;
	double		yinterept;
	double		xstep;
	double		ystep;
	double		next_touch_x;
	double		next_touch_y;
	double		wall_hit_x;
	double		wall_hit_y;
	double		dist;
	int			found_horz_wall;
	int			found_vert_wall;
	int			minus_y;
	int			minus_x;
}				t_cast;
typedef	struct s_cub
{
	void	*ptr;
	void	*win;
	int		h;
	int		w;
	
}			t_cub;

typedef struct	s_map
{
	char		*ptr;
	char		**map;
	int			w;
	int			h;
}				t_map;

typedef struct	s_is_set_el
{
	int			resolu;
	int			text_no;
	int			text_so;
	int			text_we;
	int			text_ea;
	int			sprite;
	int			color_f;
	int			color_c;
	int			player;
}				t_is_set_el;
typedef struct	s_texture
{
	char		*path;
	int			*data;
	void		*img;
	int			w;
	int			h;
	int			size_line;
}				t_texture;



typedef	struct	s_sp_cast
{
	int			hit_horz;
	int			hit_vert;
	double		hit_x;
	double		hit_y;
	double		dist;
	int			index_x;
	int			index_y;
}				t_sp_cast;
typedef struct	s_sprite
{
	double		x;
	double		y;
	int			index_x;
	int			index_y;
	double		dist;
	int			num_ray;
	double		angle;
}				t_sprite;

typedef	struct	s_img_bmp
{
	int			h;
	int			w;
	void		*img;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img_bmp;

t_player    	player;
t_rays      	*rays;
t_cub			g_cub;
t_map			g_map;
t_is_set_el		g_is_set;
t_texture		g_text_sp;
t_texture		g_text_no;
t_texture		g_text_so;
t_texture		g_text_we;
t_texture		g_text_ea;
t_sprite		*g_sprites;
t_img_bmp		g_pl_img;


int         		ft_checkwall(float x, float y, int i);
int         		ft_render_box(int x, int y, int color);
int         		ft_render_map(void);
int         		ft_render_player(void);
int         		deal_key(int key);
int					dealtow(int key);
void        		ft_castallrays(void);
int         		ft_update(void);
void        		my_pixel_put(void *img, int x, int y, int color);
int					key_release(int key);
t_cast				vertical_intersections(t_ray ray);
t_cast	    		horizontal_intersections(t_ray ray);
int					key_press(int key);
int		   			has_wall(int x, int y);
float       		normalize_angle(float angle);
float	   			dist(float x1, float y1, float x2, float y2);
int					ft_perror(const char *s);
void        		generate3DProjection();
void				create_strip_height(float tab[], int color);
void				create_strip_wall(float tab[], int offset_x, int n_ray);
int					is_player(char c);
void				get_position_player(char c, int pos_x, int pos_y);
int					is_all_elem(void);
void				reset_elem_conf(void);
void				import_data(void);
long	double		ft_atoi_parse(char *str, int *len);
int					is_player(char c);
void				get_position_player(char c, int pos_x, int pos_y);
int					is_all_elem(void);
void				reset_elem_conf(void);
void				import_map(char *line);
void				fill_map(void);
void				resolution(char **ptr);
void				color_flo_cei(char *line);
void				get_path_texture(char *line);
int					is_path_texture(char *line);
void				get_texture_sprite(void);
void				get_texture(void);
int					is_valid_ext(char *file, char *ext);
void				check_map(void);
void				get_args(int argc, char *argv[]);
void				create_strip_sprite(float tab[], int num_sp);
void				render3d(void);
void				draw_rays(void);
int					finalize(void *s);
int					mainmain(void);

#endif
