/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:16:47 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/10 11:37:12 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 void   ft_castAllRays(void)
{
    int i;

    i = 1;
        rays[0].angle = (player.rotationAngle - (FOV_ANGLE / 2));

    while (i < g_num_rays)
    {
        rays[i].angle = (rays[i - 1].angle + (FOV_ANGLE / g_num_rays));
        //printf ("%f\n", rays[i].angle);
        i++;
     }

	int line;
    int r1;
    int r2;
    int color;

    color = 0x0070FF;
	line = 600;
    i = 0;

    while(i < g_num_rays)
    {
        line = 600;
	    while (line--)
        {
            r1 = (player.x  + PLAYERR) + line * cos(rays[i].angle);
            r2 = (player.y  + PLAYERR) + line * sin(rays[i].angle);
            my_pixel_put(g_img, r1, r2, color);
        }
        i++;
    }
}
