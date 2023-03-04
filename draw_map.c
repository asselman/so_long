/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:55:29 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 15:56:05 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_data *d)
{
	d->img = mlx_xpm_file_to_image(d->mlx, "./bg/boxbg.xpm", &d->x, &d->y);
	d->imgcoin = mlx_xpm_file_to_image(d->mlx, "./cn/coin1_.xpm", &d->x, &d->y);
	d->imgb = mlx_xpm_file_to_image(d->mlx, "./bg/w.xpm", &d->x, &d->y);
	d->imgp = mlx_xpm_file_to_image(d->mlx, "./c/gaot8.xpm", &d->x, &d->y);
	d->imgdoor = mlx_xpm_file_to_image(d->mlx, "./door/door.xpm", &d->x, &d->y);
}

void	put_img(char c, t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->imgb, d->posy, d->posx);
	if (c == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->posy, d->posx);
	else if (c == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->imgp, d->posy, d->posx);
	else if (c == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->imgcoin, d->posy, d->posx);
	else if (c == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->imgdoor, d->posy, d->posx);
}

int	draw_map(t_data *data)
{
	int	ww;
	int	i;

	i = 0;
	ww = 0;
	data->posy = 0;
	data->posx = 0;
	set_images(data);
	while (ww != data->w)
	{
		data->posy = 0;
		while (data->map[ww][i])
		{
			put_img(data->map[ww][i], data);
			data->posy = data->posy + 50;
			i++;
		}
		data->posx = data->posx + 50;
		i = 0;
		ww++;
	}
	return (0);
}
