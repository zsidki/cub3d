/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:05 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/10 11:36:01 by zsidki           ###   ########.fr       */
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
			my_pixel_put(g_img, i, j, color);
			j++;
		}
		i++;
	}
	return (0);
}
