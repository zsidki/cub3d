/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:17:05 by zsidki            #+#    #+#             */
/*   Updated: 2021/02/02 11:12:48 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void		check_error(char *str)
{
	if ((*str < '0' || *str > '9') && *str != '\0' && *str != ' ')
		ft_perror("Invalid character7 ; !!\n");
	while (*str)
	{
		if (*str != '\0' && *str != ' ')
			ft_perror("Invalid character9 ; !!\n");
		str++;
	}
}

long	double		ft_atoi_parse(char *str, int *len)
{
	long	double	ch;
	int				sign;
	int				space;

	ch = 0;
	sign = 1;
	space = 0;
	*len = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' ||
			*str == '\r' || *str == '\t' || *str == '\f')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		space = 1;
		ch = (ch * 10) + *str - '0';
		if (ch > 20000)
			(*len) = 1;
		str++;
	}
	if (!space)
		ft_perror("Invalid character8 ; !!\n");

	check_error(str);
	if (*len)
		return (30000);
	return (sign * ch);
}
