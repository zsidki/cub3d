/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rander_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:25:21 by zsidki            #+#    #+#             */
/*   Updated: 2020/12/08 13:20:31 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_render_map(void)
{
	int i;
	int j;
	int imap;
	int jmap;

	i = 0;
	j = 0;
	imap = 0;
	jmap = 0;

	while (imap < MAPWIDTH)
	{
		j = 0;
		jmap = 0;
		while (jmap < MAPHEIGHT)
		{
			if (Map[jmap][imap] != 0)
				ft_render_box(i, j);
			jmap++;
			j += TILE_SIZE;
		}
		i += TILE_SIZE;
		imap++;
	}
	return (0);
}
