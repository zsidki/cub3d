/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:05 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/03 19:46:30 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_render_box(int x, int y)
{
	int i;
	int j;
	int color;

	i = x;
	j = y;
	while (i <= TILE_SIZE + x)
	{
		j = y;
		while (j <= TILE_SIZE + y)
		{
			color = 0xFFFF00;
			mlx_pixel_put(g_mlx_ptr, g_win_ptr, i, j, color);
			j++;
		}
		i++;
	}
	return (0);
}
