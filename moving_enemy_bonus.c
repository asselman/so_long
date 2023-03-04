/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:54:01 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 16:22:39 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_r_l(t_data *data, int k, int x, int y)
{
	int	n;
	int	arr[3];

	arr[0] = y - 1;
	arr[1] = y + 1;
	if (k == 2000)
	{
		n = (rand() % 2);
		if (data->map[x][arr[n]] == '0' || data->map[x][arr[n]] == 'P')
		{
			if (data->map[x][arr[n]] == 'P')
			{
				data->player_dead = 1;
				mlx_loop_hook(data->mlx, animated_lose, data);
			}
			data->map[x][arr[n]] = 'X';
			data->map[x][y] = '0';
			ft_draw(data, 'X', data->imgx, data->imgb);
		}
	}
}

void	ft_move_u_d(t_data *data, int k, int x, int y)
{
	int	m;
	int	arr[5];

	arr[0] = x - 1;
	arr[1] = x + 1;
	if (k == 1000)
	{
		m = (rand() % 2);
		if (data->map[arr[m]][y] == '0' || data->map[arr[m]][y] == 'P')
		{
			if (data->map[arr[m]][y] == 'P')
			{
				data->player_dead = 1;
				mlx_loop_hook(data->mlx, animated_lose, data);
			}
			data->map[arr[m]][y] = 'X';
			data->map[x][y] = '0';
			ft_draw(data, 'X', data->imgx, data->imgb);
		}
	}
}

void	moving_enemy(t_data *data)
{
	static int	k;
	static int	t;
	int			x;
	int			y;

	if (t == data->en)
		t = 0;
	x = data->pos_x[t][0];
	y = data->pos_x[t][1];
	k++;
	ft_move_u_d(data, k, x, y);
	ft_move_r_l(data, k, x, y);
	if (k == 2000)
	{
		k = 0;
		t++;
	}
}
