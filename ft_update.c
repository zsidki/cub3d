/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:33:41 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/09 17:28:17 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_update(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (g_keys[i])
			deal_key(g_keys[i]);
		i++;
	}
	clear_sprites();
	ft_castallrays();
	render3d();
	return (0);
}
