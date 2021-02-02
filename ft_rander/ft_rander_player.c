/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:28:09 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/02 11:06:55 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_render_player(void)
{
	int i;
	int j;
	int x1;
	int y1;

	i = player.x;
	j = player.y;
	while (i <= PLAYERR + player.x)
	{
		j = player.y;
		while (j <= PLAYERR + player.y)
		{
			my_pixel_put(g_img, i, j, 0xFF0000);
			x1 = (player.x + PLAYERR) * cos(player.rotationAngle);
			y1 = (player.y + PLAYERR) * sin(player.rotationAngle);
			my_pixel_put(g_img, x1, y1, 0xFF0000);
			j++;
		}
		i++;
	}
	return (0);
}
