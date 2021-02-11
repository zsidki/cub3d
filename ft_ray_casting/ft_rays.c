/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:42:31 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/11 16:54:14 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	get_sprites(t_cast vert, t_cast horz, float dist_wall)
{
	int			i;

	i = 0;
	while (i < (vert.i_sp + 1))
	{
		if (vert.sprite[i].dist < dist_wall)
			get_sprite_data(vert.sprite[i]);
		i++;
	}
	i = 0;
	while (i < (horz.i_sp + 1))
	{
		if (horz.sprite[i].dist < dist_wall)
			get_sprite_data(horz.sprite[i]);
		i++;
	}
}

void			draw_rays(void)
{
	int line;
	int r1;
	int r2;
	int color;
	int i;

	color = 0x0070FF;
	i = 0;
	while (i < g_num_rays)
	{
		line = g_rays[i].dist;
		while (line--)
		{
			r1 = (g_player.x + PLAYERR) + line * cos(g_rays[i].angle);
			r2 = (g_player.y + PLAYERR) + line * sin(g_rays[i].angle);
			my_pixel_put(g_img, r1, r2, color);
		}
		i++;
	}
}

static	t_ray	direction_ray(float angle, int n_ray)
{
	t_ray		ray;

	ray.angle = angle;
	ray.is_down = ray.angle > 0 && ray.angle < M_PI;
	ray.is_up = !ray.is_down;
	ray.is_right = ray.angle >= (M_PI * 3 / 2) || ray.angle <= (M_PI / 2);
	ray.is_left = !ray.is_right;
	g_rays[n_ray].angle = angle;
	g_rays[n_ray].is_down = ray.angle > 0 && ray.angle < M_PI;
	g_rays[n_ray].is_up = !ray.is_down;
	g_rays[n_ray].is_right = ray.angle >= (M_PI * 3 / 2) ||
		ray.angle <= (M_PI / 2);
	g_rays[n_ray].is_left = !ray.is_right;
	return (ray);
}

static	void	cast_ray(t_ray ray, int ray_count)
{
	t_cast	vert;
	t_cast	horz;

	vert = vertical_intersections(ray);
	horz = horizontal_intersections(ray);
	g_rays[ray_count].wall_hit.x = ((horz.found_horz_wall &&
			(horz.dist < vert.dist))) ? horz.wall_hit_x : vert.wall_hit_x;
	g_rays[ray_count].wall_hit.y = ((horz.found_horz_wall &&
			(horz.dist < vert.dist))) ? horz.wall_hit_y : vert.wall_hit_y;
	g_rays[ray_count].dist = (horz.dist < vert.dist) ? horz.dist : vert.dist;
	if (vert.i_sp >= 0 || horz.i_sp >= 0)
		get_sprites(vert, horz, g_rays[ray_count].dist);
	if (vert.dist < horz.dist)
		g_rays[ray_count].was_hit_vertical = 1;
	else
		g_rays[ray_count].was_hit_vertical = 0;
	if (vert.sprite && horz.sprite)
	{
		free(vert.sprite);
		free(horz.sprite);
	}
}

void			ft_castallrays(void)
{
	int i;

	i = 1;
	g_rays[0].angle = normalize_angle(g_player.rotationangle -
	((FOV_ANGLE) / 2));
	cast_ray(direction_ray(g_rays[0].angle, 0), 0);
	while (i < g_num_rays)
	{
		g_rays[i].angle = normalize_angle(g_rays[i - 1].angle +
		((FOV_ANGLE) / g_num_rays));
		cast_ray(direction_ray(g_rays[i].angle, i), i);
		i++;
	}
}
