/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:27:04 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/11 19:33:03 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CUB3D
# define SCREENWIDTH 670
# define SCREENHEIGHT 480
# define MAPWIDTH 21
# define MAPHEIGHT 15
# define TILE_SIZE 32
# define PLAYERR 2
# define WALKSTEP 3
# define FOV_ANGLE 60 * (M_PI / 180)

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void    *g_mlx_ptr;
void    *g_win_ptr;
void    *g_img;
void	*param;
int     g_num_rays;
int     g_keys[7];

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

}           t_player;

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

// typedef struct t_intersection
// {
//     double Bx;
//     double By;
// 	double right;
//     double l;
//     int i; 
//     int j;
// }               t_intersection;

// t_intersection intersection;
t_player    player;
t_rays      *rays;

int         ft_checkwall(float x, float y, int i);
int         ft_render_box(int x, int y);
int         ft_render_map(void);
int         ft_render_player(void);
int         deal_key(int key);
int         Map[MAPHEIGHT][MAPWIDTH];
void        ft_castAllRays(void);
int         ft_update(void);
void        my_pixel_put(void *img, int x, int y, int color);
int			key_release(int key);
t_cast		vertical_intersections(t_ray ray);
t_cast	    horizontal_intersections(t_ray ray);
int			key_press(int key);
int		    has_wall(int x, int y);

// t_intersection      vertical(double alphaa);
float       normalize_angle(float angle);
float	    dist(float x1, float y1, float x2, float y2);
#endif
