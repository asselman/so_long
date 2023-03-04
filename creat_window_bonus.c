/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:23:00 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/16 17:51:57 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_tokens_bonus(char **map, int w, int *c, int *p)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (j != w)
	{
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'P'
				&& map[j][i] != 'E' && map[j][i] != 'C' && map[j][i] != 'X')
			{
				ft_printf("You have an unacceptable item in the map ");
				ft_printf("exactly in the line %d index %d\n", j + 1, i + 1);
				exit(0);
			}
			if (map[j][i] == 'C')
				(*c)++;
			if (map[j][i] == 'P')
				(*p)++;
			i++;
		}
		i = 0;
		j++;
	}
}

void	check_p_c_bonus(int pc, int c)
{
	if (pc >= 2 || pc == 0)
	{
		ft_printf("you have %d players and ", pc);
		ft_printf("that unacceptable, check your map \n");
		exit(0);
	}
	if (c == 0)
	{
		ft_printf("you have %d coins and ", c);
		ft_printf("that unacceptable, check your map \n");
		exit(0);
	}
}

void	check_door_bonus(char **map, int w)
{
	int	j;
	int	i;
	int	en;

	en = 0;
	i = 0;
	j = 1;
	while (j != w)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				en++;
			i++;
		}
		i = 0;
		j++;
	}
	if (en > 1 || en == 0)
	{
		ft_printf("you have a %d doors and ", en);
		ft_printf("that unacceptable, check your map ");
		exit(1);
	}
}

void	contuneof_func_bonus(t_data *data, char *filename)
{
	int	fd;
	int	fd2;
	int	fd3;

	data->y = 50;
	data->x = 50;
	fd = open(filename, O_RDONLY);
	check_map(fd, &data->w, &data->len);
	close(fd);
	fd2 = open(filename, O_RDONLY);
	data->map = get_map(fd2, data->w);
	fd3 = open(filename, O_RDONLY);
	data->fakemap = get_map(fd3, data->w);
	check_lastline_bonus(data->map, data->w - 1);
	check_tokens_bonus(data->map, data->w, &data->coin, &data->pc);
	check_door_bonus(data->map, data->w);
	check_p_c_bonus(data->pc, data->coin);
	place_p_bonus(data);
	count_x(data->map, data->w, &data->en);
}

void	start_game(t_data *data, char *filename)
{
	contuneof_func_bonus(data, filename);
	check_pathmain(data);
	data->y = data->y * data->len;
	data->x = data->x * data->w;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->y, data->x, "so_long");
	mlx_hook(data->win, 2, 0, handel_key, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	draw_map(data);
	mlx_string_put(data->mlx, data->win, 5, 15, 0x9e9e9e, "moves: ");
	mlx_loop_hook(data->mlx, animation, data);
	mlx_loop(data->mlx);
}
