/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:05 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/22 12:38:35 by zsidki           ###   ########.fr       */
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
