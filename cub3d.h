/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:27:04 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/17 11:44:56 by zsidki           ###   ########.fr       */
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



typedef struct  s_rays
{
    float angle;
    
}           t_rays;

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
int			key_press(int key);

#endif
