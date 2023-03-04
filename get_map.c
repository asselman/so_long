/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:08:12 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/15 16:59:29 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_lastline(char **map, int row)
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

void	place_p(t_data *data)
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
