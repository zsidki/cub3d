/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:22:34 by zsidki            #+#    #+#             */
/*   Updated: 2021/01/22 11:24:12 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_arr_space(int i, int j)
{
	if (i > 0 && g_map.map[i - 1][j] != ' ' && g_map.map[i - 1][j] != '1')
		return (0);
	if (i < g_map.h - 1 && g_map.map[i + 1][j]
	!= ' ' && g_map.map[i + 1][j] != '1')
		return (0);
	if (j > 0 && g_map.map[i][j - 1] != ' ' && g_map.map[i][j - 1] != '1')
		return (0);
	if (j < g_map.w - 1 && g_map.map[i][j + 1]
	!= ' ' && g_map.map[i][j + 1] != '1')
		return (0);
	return (1);
}

void	check_map(void)
{
	int i;
	int j;

	i = 0;
	if (!g_is_set.player)
		ft_perror("There is no player in Map !!\n");
	while (i++ < g_map.h)
	{
		j = 0;
		while (j++ < g_map.w)
		{
			if (i - 1 == 0 || j - 1 == 0 || i - 1 == g_map.h - 1 ||
					j - 1 == g_map.w - 1)
				if (g_map.map[i - 1][j - 1] == '0')
					ft_perror("Invalid Map ; Brorders are Open  (Zero) !!");
			if (g_map.map[i - 1][j - 1] == ' ')
				if (!check_arr_space(i - 1, j - 1))
					ft_perror("Invalid Map ; Brorders are Open (Space) !!");
		}
	}
}
