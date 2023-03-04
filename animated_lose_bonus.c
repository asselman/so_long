/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_lose_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:34:38 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 16:39:38 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	contune_animated_lose(t_data *d, int i, int x, int y)
{
	if (i == 6000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/N4.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 7500)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/N5.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 9000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/N6.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
		ft_putstr_fd("\033[1;31mYOU LOSE\033[0m\n", 2);
		free_destroy(d, 0);
	}
}

void	animated_lose_p(t_data *d, int x, int y)
{
	static int	i;

	i++;
	if (i == 1500)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/n1.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 3000)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/N2.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	if (i == 4500)
	{
		mlx_destroy_image(d->mlx, d->imgp);
		d->imgp = mlx_xpm_file_to_image(d->mlx, "c/N3.xpm", &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgb, x, y);
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, x, y);
	}
	contune_animated_lose(d, i, x, y);
}

int	animated_lose(t_data *data)
{
	int	x;
	int	y;

	x = data->index * 50;
	y = data->line * 50;
	animated_lose_p(data, x, y);
	return (0);
}
