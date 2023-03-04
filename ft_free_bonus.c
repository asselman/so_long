/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:32:14 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 16:51:25 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_maps(t_data *data)
{
	int	m;

	m = 0;
	if (data->map)
	{
		while (m != data->w)
		{
			free(data->map[m]);
			m++;
		}
		free(data->map);
		m = 0;
	}
	if (data->fakemap)
	{
		while (m != data->w)
		{
			free(data->fakemap[m]);
			m++;
		}
		free(data->fakemap);
	}
}

void	free_arr(t_data *data)
{
	if (data->pos_x)
	{
		free(data->pos_x[0]);
		free(data->pos_x[1]);
		free(data->pos_x);
	}
}

void	free_destroy(t_data *data, int x)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_image(data->mlx, data->imgb);
		mlx_destroy_image(data->mlx, data->imgcoin);
		mlx_destroy_image(data->mlx, data->imgdoor);
		mlx_destroy_image(data->mlx, data->imgp);
		mlx_destroy_image(data->mlx, data->imgx);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free_maps(data);
	free_arr(data);
	free(data);
	if (x == 0)
		exit(0);
	if (x == 1)
		exit(1);
}
