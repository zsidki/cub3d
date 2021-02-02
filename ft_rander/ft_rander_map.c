/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:25:21 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/02 10:55:23 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_render_map(void)
{
	int i;
	int j;
	int imap;
	int jmap;

	i = 0;
	j = 0;
	imap = -1;
	jmap = 0;
	while (++imap < g_map.w)
	{
		j = 0;
		jmap = -1;
		while (++jmap < g_map.h)
		{
			if (g_map.map[jmap][imap] == '1')
				ft_render_box(i, j, 0xFFFF00);
			if (g_map.map[jmap][imap] == '2')
				ft_render_box(i, j, 0x00FF0F);
			j += g_tile;
		}
		i += g_tile;
	}
	return (0);
}
