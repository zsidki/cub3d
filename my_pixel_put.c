/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:34:18 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/08 15:34:33 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_pixel_put(void *img, int x, int y, int color)
{
	int bits_per_pixel;
	int size_line;
	int endian;
	int *var;

	var = (int*)mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	if (x < g_cub.w && x >= 0 && y < g_cub.h && y >= 0)
		var[x + y * size_line / 4] = color;
}
