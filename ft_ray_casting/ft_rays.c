/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:16:47 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/02 11:11:45 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		line = rays[i].dist;
		while (line--)
		{
			r1 = (player.x + PLAYERR) + line * cos(rays[i].angle);
			r2 = (player.y + PLAYERR) + line * sin(rays[i].angle);
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
	rays[n_ray].angle = angle;
	rays[n_ray].is_down = ray.angle > 0 && ray.angle < M_PI;
	rays[n_ray].is_up = !ray.is_down;
	rays[n_ray].is_right = ray.angle >= (M_PI * 3 / 2) ||
		ray.angle <= (M_PI / 2);
	rays[n_ray].is_left = !ray.is_right;
	return (ray);
}

static	void	cast_ray(t_ray ray, int ray_count)
{
	t_cast	vert;
	t_cast	horz;

	vert = vertical_intersections(ray);
	horz = horizontal_intersections(ray);
	rays[ray_count].wall_hit.x = ((horz.found_horz_wall &&
			(horz.dist < vert.dist))) ? horz.wall_hit_x : vert.wall_hit_x;
	rays[ray_count].wall_hit.y = ((horz.found_horz_wall &&
			(horz.dist < vert.dist))) ? horz.wall_hit_y : vert.wall_hit_y;
	rays[ray_count].dist = (horz.dist < vert.dist) ? horz.dist : vert.dist;
	if (vert.dist < horz.dist)
		rays[ray_count].was_hit_vertical = 1;
	else
		rays[ray_count].was_hit_vertical = 0;
}

void			ft_castallrays(void)
{
	int i;

	i = 1;
	rays[0].angle = normalize_angle(player.rotationAngle - (FOV_ANGLE / 2));
	cast_ray(direction_ray(rays[0].angle, 0), 0);
	while (i < g_num_rays)
	{
		rays[i].angle = normalize_angle(rays[i - 1].angle +
		(FOV_ANGLE / g_num_rays));
		cast_ray(direction_ray(rays[i].angle, i), i);
		i++;
	}
}
