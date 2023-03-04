/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:51 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/14 23:58:27 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_filemap(char *filemap, t_data *data)
{
	int		i;

	i = ft_strlen(filemap) - 1;
	if (filemap[i - 3] != '.' && filemap[i - 2] != 'b'
		&& filemap[i - 1] != 'e' && filemap[i] != 'r')
	{
		ft_putstr_fd("\033[1;31mERROR\033[0m: ", 2);
		ft_putstr_fd("your file doesn't eneding by the extension .ber\n", 2);
		free(data);
		exit(1);
	}
}

int	main(int argC, char **argV)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	ft_memset(data, 0, sizeof(t_data));
	if (argC == 1)
	{
		ft_putstr_fd("\033[1;31mERROR\033[0m: please enter the map\n", 2);
		free(data);
		exit(1);
	}
	if (argC >= 3)
	{
		ft_putstr_fd("\033[1;31mERROR\033[0m: you enter more than 1 map\n", 2);
		free(data);
		exit(1);
	}
	check_filemap(argV[1], data);
	start_game(data, argV[1]);
	return (0);
}
