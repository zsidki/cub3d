/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_data_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:01:22 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/22 10:45:35 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static	void	oriontation_player(char c)
{
	if (c == 'N')
		player.rotationAngle = M_PI * 3 / 2;
	if (c == 'S')
		player.rotationAngle = M_PI / 2;
	if (c == 'E')
		player.rotationAngle = 0;
	if (c == 'W')
		player.rotationAngle = M_PI;
}

void			get_position_player(char c, int pos_x, int pos_y)
{
	g_is_set.player = (g_is_set.player == 0) ?
			1 : ft_perror("Duplicate player; Set One Position !");
	oriontation_player(c);
	player.x = (pos_y * g_tile) + (g_tile / 2);
	player.y = (pos_x * g_tile) + (g_tile / 2);
}

int				is_all_elem(void)
{
	if (g_is_set.resolu && g_is_set.text_no && g_is_set.text_so
			&& g_is_set.text_we && g_is_set.text_ea && g_is_set.sprite
			&& g_is_set.color_c && g_is_set.color_f)
		return (1);
	return (0);
}

void			reset_elem_conf(void)
{
	g_is_set.resolu = 0;
	g_is_set.text_no = 0;
	g_is_set.text_so = 0;
	g_is_set.text_we = 0;
	g_is_set.text_ea = 0;
	g_is_set.sprite = 0;
	g_is_set.color_c = 0;
	g_is_set.color_f = 0;
	g_is_set.player = 0;
}