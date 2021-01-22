/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate3D.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:28:12 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/22 12:38:35 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void        generate3DProjection() 
// {
//     unsigned int Uint32;
//     Uint32* colorBuffer = NULL;
//     free(colorBuffer);


//     for (int i = 0; i < g_num_rays; i++) 
//     {
//         float perpDistance = rays[i].dist * cos(rays[i].angle - player.rotationAngle);
//         float distanceProjPlane = (g_cub.w / 2) / tan(FOV_ANGLE / 2);
//         float projectedWallHeight = (g_tile / perpDistance) * distanceProjPlane;

//         int wallStripHeight = (int)projectedWallHeight;

//         int wallTopPixel = (g_cub.h / 2) - (wallStripHeight / 2);
//         wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

//         int wallBottomPixel = (g_cub.h / 2) + (wallStripHeight / 2);
//         wallBottomPixel = wallBottomPixel > g_cub.h ? g_cub.h : wallBottomPixel;
//         colorBuffer = (int*)malloc(sizeof(int) * g_cub.w * g_cub.h);

//         // render the wall from wallTopPixel to wallBottomPixel
//         for (int y = wallTopPixel; y < wallBottomPixel; y++) {
//             colorBuffer[(g_cub.w * y) + i] = rays[i].was_hit_vertical ? 0xFFFFFFFF : 0xFFCCCCCC;
//         }
//     }
// }
