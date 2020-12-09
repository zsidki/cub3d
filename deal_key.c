/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:35:12 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/04 12:15:29 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key(int key, void *param)
{
	param = NULL;
	if (key == 53)
		exit(0);
	if (key == 0)
	{
		player.walkDirection = -1;
		player.x -= WALKSTEP;
	}//a
	if (key == 1)
	{
		player.walkDirection = -1;
		player.y -= WALKSTEP * sin(player.rotationAngle);
		player.x -= WALKSTEP * cos(player.rotationAngle);
	}//s
	if (key == 2)
	{
		player.walkDirection = +1;
		player.x += WALKSTEP;
	}//d
	if (key == 13)
	{
		player.walkDirection = +1;
		player.y += WALKSTEP * sin(player.rotationAngle);
		player.x += WALKSTEP * cos(player.rotationAngle);
	}//w
	if (key == 123)
	{
		player.rotationAngle -= 20 * M_PI / 180;
	}//arrow lift
	if (key == 124)
	{
		player.rotationAngle += 20 * M_PI / 180;
	}//arrow right
	mlx_destroy_image(g_mlx_ptr, g_img);
	g_img = mlx_new_image(g_mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img, 0, 0);
	ft_render_map();
	ft_render_player();
	ft_castAllRays();
	return (0);
}
