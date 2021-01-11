/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:59:32 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/11 19:31:13 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


float	normalize_angle(float angle)
{
	float new_angle;

	new_angle = fmod(angle, (2 * M_PI)); // float mod
	if (new_angle < 0)
		new_angle += (2 * M_PI);
	return (new_angle);
}

int		has_wall(int x, int y)
{
	int	index_x;
	int	index_y;

	index_x = x / TILE_SIZE;
	index_y = y / TILE_SIZE;
	if (index_y < MAPHEIGHT && index_x < MAPWIDTH)
	{
		if (Map[index_y][index_x] == 1)
			return (1);
		else if (Map[index_y][index_x] == 2)
			return (2);
	}
	return (0);
}

float	dist(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}