/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:31:56 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 15:55:10 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	calculate_moves_bonus(t_data *data, int move)
{
	char	*str;

	str = ft_itoa(move);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 100, 0);
	mlx_string_put(data->mlx, data->win, 5, 15, 0x9e9e9e, "moves: ");
	mlx_string_put(data->mlx, data->win, 75, 15, 0x9e9e9e, str);
	free(str);
}
