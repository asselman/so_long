/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_in_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:08:33 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 17:05:36 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(t_data *data, int *move)
{
	if (data->map[data->line - 1][data->index] == '1')
		return (0);
	else if (data->map[data->line - 1][data->index] == 'C')
		data->coin--;
	if (data->map[data->line - 1][data->index] == 'E' && data->coin == 0)
	{
		ft_putstr_fd("\033[1;32mYOU WIN\033[0m", 2);
		free_destroy(data, 0);
	}
	else if (data->map[data->line - 1][data->index] == 'E' && data->coin != 0)
		return (0);
	data->map[data->line - 1][data->index] = 'P';
	data->map[data->line][data->index] = '0';
	draw_map(data);
	(*move)++;
	ft_printf("moves=>: (%d)\n", *move);
	data->line--;
	return (1);
}

int	ft_move_down(t_data *data, int *move)
{
	if (data->map[data->line + 1][data->index] == '1')
		return (0);
	if (data->map[data->line + 1][data->index] == 'C')
		data->coin--;
	if (data->map[data->line + 1][data->index] == 'E' && data->coin == 0)
	{
		ft_putstr_fd("\033[1;32mYOU WIN\033[0m", 2);
		free_destroy(data, 0);
	}
	else if (data->map[data->line + 1][data->index] == 'E' && data->coin != 0)
		return (0);
	data->map[data->line + 1][data->index] = 'P';
	data->map[data->line][data->index] = '0';
	draw_map(data);
	(*move)++;
	ft_printf("moves=>: (%d)\n", *move);
	data->line++;
	return (1);
}

int	ft_move_left(t_data *data, int *move)
{
	if (data->map[data->line][data->index - 1] == '1')
		return (0);
	if (data->map[data->line][data->index - 1] == 'C')
		data->coin--;
	if (data->map[data->line][data->index - 1] == 'E' && data->coin == 0)
	{
		ft_putstr_fd("\033[1;32mYOU WIN\033[0m", 2);
		free_destroy(data, 0);
	}
	else if (data->map[data->line][data->index - 1] == 'E' && data->coin != 0)
		return (0);
	data->map[data->line][data->index - 1] = 'P';
	data->map[data->line][data->index] = '0';
	draw_map(data);
	(*move)++;
	ft_printf("moves=>: (%d)\n", *move);
	data->index--;
	return (1);
}

int	ft_move_right(t_data *data, int *move)
{
	if (data->map[data->line][data->index + 1] == '1')
		return (0);
	if (data->map[data->line][data->index + 1] == 'C')
		data->coin--;
	if (data->map[data->line][data->index + 1] == 'E' && data->coin == 0)
	{
		ft_putstr_fd("\033[1;32mYOU WIN\033[0m", 2);
		free_destroy(data, 0);
	}
	else if (data->map[data->line][data->index + 1] == 'E' && data->coin != 0)
		return (0);
	data->map[data->line][data->index + 1] = 'P';
	data->map[data->line][data->index] = '0';
	draw_map(data);
	(*move)++;
	ft_printf("moves=>: (%d)\n", *move);
	data->index++;
	return (1);
}

int	handel_key(int key, t_data *data)
{
	static int	move;

	if (key == 13)
		if (ft_move_up(data, &move) == 0)
			return (0);
	if (key == 1)
		if (ft_move_down(data, &move) == 0)
			return (0);
	if (key == 0)
		if (ft_move_left(data, &move) == 0)
			return (0);
	if (key == 2)
		if (ft_move_right(data, &move) == 0)
			return (0);
	if (key == 53)
		exit(0);
	return (0);
}
