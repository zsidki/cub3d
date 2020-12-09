/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:35:12 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/09 20:30:31 by zsidki           ###   ########.fr       */
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
		ft_update();
	}//a
	if (key == 1)
	{
		player.walkDirection = -1;
		player.y -= WALKSTEP * sin(player.rotationAngle);
		player.x -= WALKSTEP * cos(player.rotationAngle);
		ft_update();
	}//s
	if (key == 2)
	{
		player.walkDirection = +1;
		player.x += WALKSTEP;
		ft_update();
	}//d
	if (key == 13)
	{
		player.walkDirection = +1;
		player.y += WALKSTEP * sin(player.rotationAngle);
		player.x += WALKSTEP * cos(player.rotationAngle);
		ft_update();
	}//w
	if (key == 123)
	{
		player.rotationAngle -= 5 * M_PI / 180;
		ft_update();
	}//arrow lift
	if (key == 124)
	{
		player.rotationAngle += 5 * M_PI / 180;
		ft_update();
	}//arrow right
	return (0);
}
