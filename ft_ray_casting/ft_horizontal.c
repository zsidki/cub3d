/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:14:03 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/22 12:38:35 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_cast	calculate_steps(t_cast cast, t_ray ray)
{
	cast.yinterept = floor(player.y / g_tile) * g_tile;
	cast.yinterept += (ray.is_down ? g_tile : 0);
	cast.xinterept = player.x + ((-cast.yinterept + player.y)
			/ tan(-ray.angle));
	cast.ystep = g_tile;
	cast.ystep *= ray.is_up ? -1 : 1;
	cast.xstep = cast.ystep / tan(-ray.angle);
	cast.next_touch_x = cast.xinterept;
	cast.next_touch_y = cast.yinterept;
	if (ray.is_up)
		cast.minus_y = 1;
	else
		cast.minus_y = 0;
	return (cast);
}

static t_cast	increment_steps(t_cast cast)
{
	while (cast.next_touch_x >= 0 && cast.next_touch_x <= g_tile * g_map.w
		&& cast.next_touch_y >= 0 && cast.next_touch_y <= g_tile * g_map.h)
	{
		if (has_wall(cast.next_touch_x, cast.next_touch_y - cast.minus_y) == 1)
		{
			cast.found_horz_wall = 1;
			cast.wall_hit_x = cast.next_touch_x;
			cast.wall_hit_y = cast.next_touch_y;
			break ;
		}
		cast.next_touch_x -= cast.xstep;
		cast.next_touch_y += cast.ystep;
	}
	if (!cast.found_horz_wall)
	{
		cast.wall_hit_x = player.x;
		cast.wall_hit_y = player.y;
	}
	return (cast);
}

t_cast			horizontal_intersections(t_ray ray)
{
	t_cast	cast;
	int		i;

	cast.found_horz_wall = 0;
	i = 0;
	cast = calculate_steps(cast, ray);
	cast = increment_steps(cast);
	cast.dist = (cast.found_horz_wall)
	? dist(player.x, player.y, cast.wall_hit_x, cast.wall_hit_y)
	: WINT_MAX;
	return (cast);
}