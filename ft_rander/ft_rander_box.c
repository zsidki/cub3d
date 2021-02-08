/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:40:50 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/08 15:41:01 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_render_box(int x, int y, int color)
{
	int i;
	int j;

	i = x;
	j = y;
	while (i <= g_tile + x)
	{
		j = y;
		while (j <= g_tile + y)
		{
			my_pixel_put(g_img, i, j, color);
			j++;
		}
		i++;
	}
	return (0);
}
