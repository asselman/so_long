/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:08:12 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/15 19:53:47 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**get_map(int fd, int w)
{
	char	**map;
	int		l;

	l = 0;
	map = (char **)malloc(w * sizeof(char *));
	l = 0;
	while (l != w)
	{
		map[l] = get_next_line(fd);
		l++;
	}
	return (map);
}

void	check_lastline_bonus(char **map, int row)
{
	int	i;

	i = 0;
	while (map[row][i] != '\0')
	{
		if (map[row][i] != '1')
		{
			write(1, "\033[1;31mERROR\033[0m: ", 19);
			write(1, "you have Unacceptable item in the last line\n", 45);
			exit(1);
		}
		i++;
	}
}

void	place_p_bonus(t_data *data)
{
	int	row;
	int	i;

	row = 0;
	i = 0;
	while (1)
	{
		while (data->map[row][i])
		{
			if (data->map[row][i] == 'P')
			{
				data->line = row;
				data->index = i;
				break ;
			}
			i++;
		}
		if (data->line != 0)
			break ;
		i = 0;
		row++;
	}
}

void	count_x(char **map, int row, int *x)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j != row)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'X')
				(*x)++;
			i++;
		}
		i = 0;
		j++;
	}
	if ((*x) == 0)
	{
		ft_putstr_fd("\033[1;31mERROR\033[0m: there's no enemy\n", 2);
		exit(1);
	}
}
