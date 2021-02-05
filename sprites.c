/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:01:38 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/31 15:34:02 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		in_array_sprites(int p_x, int p_y)
{
	int i;

	i = 0;
	while (i < g_index_sp)
	{
		if (g_sprites[i].index_x == p_x && g_sprites[i].index_y == p_y)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static	void	get_ray_hit_sp(float s_x, float s_y, int i_sp)
{
	double		alpha;
	t_vector	v_ray1;
	t_vector	v_sp;

	v_ray1.x = rays[0].wall_hit.x - player.x;
	v_ray1.y = rays[0].wall_hit.y - player.y;
	v_sp.x = s_x - player.x;
	v_sp.y = s_y - player.y;
	alpha = - atan2(v_ray1.y, v_ray1.x) + atan2(v_sp.y, v_sp.x);
	if (alpha > M_PI)
		alpha -= M_PI * 2;
	else if (alpha < -M_PI)
		alpha += M_PI * 2;

	g_sprites[i_sp].num_ray = (g_num_rays / (FOV_ANGLE)) * alpha;
}

void			get_sprite_data(t_sp_cast tmp_sp)
{

	if (!in_array_sprites(tmp_sp.index_x, tmp_sp.index_y))
	{
		g_sprites[g_index_sp].x = tmp_sp.hit_x;
		g_sprites[g_index_sp].y = tmp_sp.hit_y;
		g_sprites[g_index_sp].index_x = tmp_sp.index_x;
		g_sprites[g_index_sp].index_y = tmp_sp.index_y;
		g_sprites[g_index_sp].dist = tmp_sp.dist;

		get_ray_hit_sp(g_sprites[g_index_sp].x, g_sprites[g_index_sp].y,
			g_index_sp);
		g_sprites[g_index_sp].angle = normalize_angle(player.rotationAngle -
				(FOV_ANGLE) / 2) + (g_sprites[g_index_sp].num_ray *
				((FOV_ANGLE) / g_num_rays));
		g_index_sp++;
	}
}

void			sort_sprites(void)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < (g_index_sp - 1))
	{
		j = 0;
		while (j < (g_index_sp - i - 1))
		{
			if (g_sprites[j].dist < g_sprites[j + 1].dist)
			{
				tmp = g_sprites[j];
				g_sprites[j] = g_sprites[j + 1];
				g_sprites[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			clear_sprites(void)
{
	int n_sp;

	n_sp = g_n_sp;
	if (g_sprites)
	{
		free(g_sprites);
		g_sprites = NULL;
	}
	g_index_sp = 0;
	g_sprites = (t_sprite *)(malloc(n_sp * sizeof(t_sprite)));
}
