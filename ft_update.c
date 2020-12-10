/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:11:44 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/10 13:21:38 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_update(void)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (g_keys[i])
			deal_key(g_keys[i]);
		i++;
	}
	g_img = mlx_new_image(g_mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	ft_render_map();
	ft_render_player();
	ft_castAllRays();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img, 0, 0);
	mlx_destroy_image(g_mlx_ptr, g_img);
	return (0);
}
