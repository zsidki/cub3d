/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:02:29 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/10 12:37:08 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void    ft_putchar(char c)
{
	write(1, &c, 1);
}

int Map[MAPHEIGHT][MAPWIDTH]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,1},
	{1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

};


/*int ft_checkwall(float x, float y, int i)
  {
  if (Map[(int)(x / TILE_SIZE)][(int)(y / TILE_SIZE)] == 1)
  return (1);
  return 0;
  }*/


int     main()
{
	int i;

	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	
	g_num_rays = SCREENWIDTH;
	rays = (t_rays *)malloc(sizeof(t_rays) * g_num_rays);
	player.x = SCREENWIDTH / 2;
	player.y = SCREENHEIGHT / 2;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = (M_PI / 2);
	player.moveSpeed = 2.1;
	player.rotationSpeed = 1.5 * (M_PI / 180);


	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	ft_update();
	mlx_hook(g_win_ptr, 2, 1L << 0, key_press, NULL); // listen to keybord 1L << 0
	mlx_hook(g_win_ptr, 3, 1L << 1, key_release, NULL);
	mlx_loop_hook(g_mlx_ptr , ft_update, NULL);
	// mlx_hook(g_cub.win, 17, 0L, finalize, NULL); //button fquite (red x)
	// mlx_loop_hook(g_cub.ptr, update, NULL);
	mlx_loop(g_mlx_ptr);
	return 0;
}
