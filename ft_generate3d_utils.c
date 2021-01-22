/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate3d_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:35:53 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/21 17:03:37 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			create_strip_height(float tab[], int color)
{
	int j;

	j = -1;
	while (++j < tab[2])
	my_pixel_put(g_img_3d, tab[0], tab[1] + j, color);
}

void			create_strip_wall(float tab[], int offset_x, int n_ray)
{
	int		j;
	int		k;
	float	h;

	h = tab[2];
	tab[1] = tab[1] < 0 ? 0 : tab[1];
	tab[2] = tab[2] + tab[1] > g_cub.h ? g_cub.h - tab[1] : tab[2];
	j = -1;
	while (++j < tab[2])
	{
		if (rays[n_ray].was_hit_vertical && rays[n_ray].is_left)
			k = 1;
		else if (rays[n_ray].was_hit_vertical && rays[n_ray].is_right)
			k = 0;
		else if (!rays[n_ray].was_hit_vertical && rays[n_ray].is_down)
			k = 3;
		else if (!rays[n_ray].was_hit_vertical && rays[n_ray].is_up)
			k = 2;
		my_pixel_put(g_img_3d, tab[0], tab[1] + j,
			get_color_text(k, tab[1] + j + h / 2 - g_cub.h / 2, h, offset_x));
	}
}
