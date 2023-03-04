/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:45:09 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 16:23:30 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	contu_an_up_t(t_data *d, int i, int x, int y)
{
	if (i == 9000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot6.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 10500)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot7.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 12000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot8.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
}

void	contu_an_up(t_data *d, int i, int x, int y)
{
	if (i == 4500)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot3.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 6000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot4.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 75000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot5.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
}

void	animated_up(t_data *d, int x, int y)
{
	static int	i;

	i++;
	if (i == 1500)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot1.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 3000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/gaot2.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	contu_an_up(d, i, x, y);
	contu_an_up_t(d, i, x, y);
	if (i == 12000)
		i = 0;
}

int	animation(t_data *data)
{
	int	x;
	int	y;

	x = data->index * 50;
	y = data->line * 50;
	animated_up(data, x, y);
	animated_enemy(data);
	moving_enemy(data);
	return (0);
}
