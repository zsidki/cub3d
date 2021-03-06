/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:41:35 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/08 16:54:09 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_render_player(void)
{
	int i;
	int j;
	int x1;
	int y1;

	i = g_player.x;
	j = g_player.y;
	while (i <= PLAYERR + g_player.x)
	{
		j = g_player.y;
		while (j <= PLAYERR + g_player.y)
		{
			my_pixel_put(g_img, i, j, 0xFF0000);
			x1 = (g_player.x + PLAYERR) * cos(g_player.rotationangle);
			y1 = (g_player.y + PLAYERR) * sin(g_player.rotationangle);
			my_pixel_put(g_img, x1, y1, 0xFF0000);
			j++;
		}
		i++;
	}
	return (0);
}
