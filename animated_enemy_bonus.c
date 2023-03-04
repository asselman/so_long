/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:11:31 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 16:22:00 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_pos_x(t_data *data)
{
	int	j;
	int	i;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	data->pos_x = (int **)malloc(data->en * sizeof(int *));
	while (j != data->w)
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'X')
			{
				data->pos_x[k] = malloc(2 * sizeof(int));
				data->pos_x[k][0] = j;
				data->pos_x[k][1] = i;
				k++;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	contune_an(t_data *d, int i, int x, int y)
{
	int	k;

	k = 0;
	if (i == 4500)
	{
		mlx_destroy_image(d->mlx, d->imgx);
		d->imgx = mlx_xpm_file_to_image(d->mlx, "./X/d3.xpm", &d->x, &d->y);
		while (k != d->en)
		{
			x = d->pos_x[k][1] * 50;
			y = d->pos_x[k][0] * 50;
			mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
			mlx_put_image_to_window(d->mlx, d->win, d->imgx, x, y);
			k++;
		}
	}
}

void	contune_animated(t_data *d, int i, int x, int y)
{
	int	k;

	k = 0;
	if (i == 3000)
	{
		mlx_destroy_image(d->mlx, d->imgx);
		d->imgx = mlx_xpm_file_to_image(d->mlx, "./X/d2.xpm", &d->x, &d->y);
		while (k != d->en)
		{
			x = d->pos_x[k][1] * 50;
			y = d->pos_x[k][0] * 50;
			mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
			mlx_put_image_to_window(d->mlx, d->win, d->imgx, x, y);
			k++;
		}
	}
	contune_an(d, i, x, y);
}

void	animated_e(t_data *d)
{
	static int	i;
	static int	x;
	static int	y;
	int			k;

	k = 0;
	i++;
	if (i == 1500)
	{
		mlx_destroy_image(d->mlx, d->imgx);
		d->imgx = mlx_xpm_file_to_image(d->mlx, "./X/d1.xpm", &d->x, &d->y);
		while (k != d->en)
		{
			x = d->pos_x[k][1] * 50;
			y = d->pos_x[k][0] * 50;
			mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
			mlx_put_image_to_window(d->mlx, d->win, d->imgx, x, y);
			k++;
		}
		k = 0;
	}
	contune_animated(d, i, x, y);
	if (i == 4500)
		i = 0;
}

void	animated_enemy(t_data *data)
{
	int	j;

	j = 0;
	if (data->pos_x != NULL)
	{
		while (j != data->en)
		{
			free(data->pos_x[j]);
			j++;
		}
		free(data->pos_x);
	}
	get_pos_x(data);
	animated_e(data);
}
