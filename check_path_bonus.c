/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:29:58 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/16 17:51:36 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_path(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != d->w)
	{
		while (d->fakemap[j][i])
		{
			if (d->fakemap[j][i] == 'P')
			{
				if (d->fakemap[j + 1][i] != '1' && d->fakemap[j + 1][i] != 'E')
					d->fakemap[j + 1][i] = 'P';
				if (d->fakemap[j][i + 1] != '1' && d->fakemap[j][i + 1] != 'E')
					d->fakemap[j][i + 1] = 'P';
				if (d->fakemap[j - 1][i] != '1' && d->fakemap[j - 1][i] != 'E')
					d->fakemap[j - 1][i] = 'P';
				if (d->fakemap[j][i - 1] != '1' && d->fakemap[j][i - 1] != 'E')
					d->fakemap[j][i - 1] = 'P';
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	check_e(char **fakemap, int j, int i, t_data *data)
{
	if (fakemap[j][i] == 'E')
	{
		if (fakemap[j + 1][i] != 'P' && fakemap[j - 1][i] != 'P'
			&& fakemap[j][i + 1] != 'P' && fakemap[j][i - 1] != 'P')
		{
			ft_putstr_fd("\033[1;31mERROR\033[0m: ", 2);
			ft_putstr_fd("player can not get the door\n", 2);
			free_destroy(data, 1);
		}
	}
}

void	check_ifvalid(t_data *data, char **fakemap, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != row)
	{
		while (fakemap[j][i])
		{
			if (fakemap[j][i] == 'C' || fakemap[j][i] == 'X')
			{
				ft_putstr_fd("\033[1;31mERROR\033[0m: invalid path, ", 2);
				ft_printf("The player cannot get this item y:%d x:%d\n", j, i);
				free_destroy(data, 1);
			}
			check_e(fakemap, j, i, data);
			i++;
		}
		i = 0;
		j++;
	}
}

void	check_pathmain(t_data *data)
{
	int	k;
	int	len;

	len = data->w * data->len;
	k = 0;
	while (k++ != len)
		check_path(data);
	check_ifvalid(data, data->fakemap, data->w);
}
