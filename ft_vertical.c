/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:13:36 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/11 19:31:58 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_cast	calculate_steps(t_cast cast, t_ray ray)
{
	cast.xinterept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	cast.xinterept += (ray.is_right ? TILE_SIZE : 0);
	cast.yinterept = player.y + ((-cast.xinterept + player.x)
		* tan(-ray.angle));
	cast.xstep = TILE_SIZE;
	cast.xstep *= ray.is_left ? -1 : 1;
	cast.ystep = cast.xstep * tan(-ray.angle);
	cast.next_touch_x = cast.xinterept;
	cast.next_touch_y = cast.yinterept;
	if (ray.is_left)
		cast.minus_x = 1;
	else
		cast.minus_x = 0;
	return (cast);
}


static t_cast	increment_steps(t_cast cast)
{
	while (cast.next_touch_x >= 0 && cast.next_touch_x <= TILE_SIZE * MAPWIDTH
			&& cast.next_touch_y >= 0 && cast.next_touch_y <= TILE_SIZE * MAPHEIGHT)
	{
		if (has_wall(cast.next_touch_x - cast.minus_x, cast.next_touch_y) == 1)
		{
			cast.found_vert_wall = 1;
			cast.wall_hit_x = cast.next_touch_x;
			cast.wall_hit_y = cast.next_touch_y;
			break ;
		}
		cast.next_touch_x += cast.xstep;
		cast.next_touch_y -= cast.ystep;
	}
	if (!cast.found_vert_wall)
	{
		cast.wall_hit_x = player.x;
		cast.wall_hit_y = player.y;
	}
	return (cast);
}

t_cast			vertical_intersections(t_ray ray)
{
	t_cast	cast;
	int		i;

	cast.found_vert_wall = 0;
	i = 0;
	cast = calculate_steps(cast, ray);
	cast = increment_steps(cast);
	cast.dist = (cast.found_vert_wall)
		? dist(player.x, player.y, cast.wall_hit_x, cast.wall_hit_y)
		: WINT_MAX;
	return (cast);
}