/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:28:09 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/10 11:36:35 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_render_player(void)
{
	int i;
	int j;
	int color;

	i = player.x;
	j = player.y;

	while (i <= PLAYERR + player.x)
	{
		j = player.y;
		while (j <= PLAYERR + player.y)
		{
			int x1;
			int y1;

			color = 0xFF0000;
			my_pixel_put(g_img, i, j, color);

			int line;
			line = 40;
			while (line--)
			{
				x1 = (player.x + PLAYERR) + line * cos(player.rotationAngle);
				y1 = (player.y + PLAYERR) + line * sin(player.rotationAngle);
				my_pixel_put(g_img, x1, y1, color);
			}
			j++;
		}
		i++;
	}
	return (0);
}
