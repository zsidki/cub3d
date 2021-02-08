/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keytwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:14:41 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/08 16:54:09 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				dealthree(int key)
{
	int x;
	int y;

	if (key == 123)
		g_player.rotationangle -= 5 * M_PI / 180;
	if (key == 124)
		g_player.rotationangle += 5 * M_PI / 180;
	if (key == 13)
	{
		g_player.walkdirection = +1;
		y = (g_player.y + 2 * WALKSTEP * sin(g_player.rotationangle)) / g_tile;
		x = (g_player.x + 2 * WALKSTEP * cos(g_player.rotationangle)) / g_tile;
		if (g_map.map[y][x] != '1')
		{
			g_player.y += WALKSTEP * sin(g_player.rotationangle);
			g_player.x += WALKSTEP * cos(g_player.rotationangle);
		}
	}
	return (0);
}
