/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:01:24 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/15 01:17:03 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen_t(char *string)
{
	int	i;

	i = 0;
	if (!(string))
		return (0);
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	return (i);
}

void	check_isvalid(int w, char *str, int i)
{
	if (w == 0)
	{
		while (str[i] == '1')
			i++;
		if (ft_strlen_t(str) != i)
		{
			printf("error in line %d in index %d", w + 1, i + 1);
			exit(1);
		}
	}
	if (w != 0)
	{
		i = 0;
		while (str[i] != '\n' && str[i] != '\0')
		{
			if ((i == 0 && str[i] != '1')
				|| (i == ft_strlen_t(str) - 1 && str[i] != '1'))
			{
				printf("error in line %d index %i", w + 1, i + 1);
				exit(1);
			}
			i++;
		}
	}
}

void	check_map(int fd, int *w, int *I)
{
	char	*str;
	int		i;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (*w == 0 && str == NULL)
		{
			ft_putstr_fd("\033[1;31mERROR\033[0m: your file are empty\n", 2);
			exit(1);
		}
		if (str == NULL)
			break ;
		if (*w == 0)
			*I = ft_strlen_t(str);
		if (ft_strlen_t(str) != *I)
		{
			printf("error line (%d) and line (%d) are not equals", *w + 1, *w);
			exit(1);
		}
		check_isvalid(*w, str, i);
		(*w)++;
		free(str);
	}
}
