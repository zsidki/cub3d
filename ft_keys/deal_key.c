/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:35:12 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/31 17:13:23 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static	void	reset_key(void) //close windows from red x
{
	int i;

	i = 0;
	while (i < 7)
		g_keys[i++] = 0;
}

int				key_release(int key) // tableau [0,0,0,0,0,0,0] keep keys numbers in orders
{
	if (key == 260 || key == 259)
		reset_key();
	if (key == 13)
		g_keys[0] = 0;
	if (key == 1)
		g_keys[1] = 0;
	if (key == 0)
		g_keys[2] = 0;
	if (key == 2)
		g_keys[3] = 0;
	if (key == 123)
		g_keys[4] = 0;
	if (key == 124)
		g_keys[5] = 0;
	return (key);
}

int				key_press(int key)
{
	if (key == 13)
		g_keys[0] = key;
	if (key == 1)
		g_keys[1] = key;
	if (key == 0)
		g_keys[2] = -5;
	if (key == 2)
		g_keys[3] = key;
	if (key == 123)
		g_keys[4] = key;
	if (key == 124)
		g_keys[5] = key;
	if (key == 53)
		g_keys[6] = key;
	return (key);
}

int		deal_key(int key)
{
		int x;
		int y;
		if (key == 53)
			exit(0);
		if (key == -5)
		{
			player.walkDirection = -1;
			y = (player.y - 2 * WALKSTEP * cos(player.rotationAngle)) / g_tile;
			x = (player.x + 2 * WALKSTEP * sin(player.rotationAngle)) / g_tile;
			if (g_map.map[y][x] != '1')
			{
				player.y -= WALKSTEP * cos(player.rotationAngle);
				player.x += WALKSTEP * sin(player.rotationAngle);
			}
		}//a
		if (key == 1)
		{
			player.walkDirection = -1;
			y = (player.y - 2 * WALKSTEP * sin(player.rotationAngle)) / g_tile;
			x = (player.x - 2 * WALKSTEP * cos(player.rotationAngle)) / g_tile;
			if (g_map.map[y][x] != '1')
			{
				player.y -= WALKSTEP * sin(player.rotationAngle);
				player.x -= WALKSTEP * cos(player.rotationAngle); 
			}
		}//s
		if (key == 2)
		{
			player.walkDirection = +1;
			y = (player.y + 2 * WALKSTEP * cos(player.rotationAngle)) / g_tile;
			x = (player.x - 2 * WALKSTEP * sin(player.rotationAngle)) / g_tile;
			if (g_map.map[y][x] != '1')
			{
				player.y += WALKSTEP * cos(player.rotationAngle);
				player.x -= WALKSTEP * sin(player.rotationAngle);
			}
		}//d
		if (key == 13)
		{
			player.walkDirection = +1;
			y = (player.y + 2 * WALKSTEP * sin(player.rotationAngle)) / g_tile;
			x = (player.x + 2 * WALKSTEP * cos(player.rotationAngle)) / g_tile;
			if (g_map.map[y][x] != '1')
			{
				player.y += WALKSTEP * sin(player.rotationAngle);
				player.x += WALKSTEP * cos(player.rotationAngle);
			}
		}//w
		if (key == 123)
			player.rotationAngle -= 5 * M_PI / 180; //arrow lift
		if (key == 124)
		player.rotationAngle += 5 * M_PI / 180; //arrow right

	return (0);
}
