/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:42:19 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/15 15:50:02 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*str;
	size_t		i;

	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

char	*ft_memcpy(char *src, char *dst)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	dst = malloc(ft_strlen(src));
	while (src[i] != '\n' && src[i] != '\0')
	{
		dst[k] = src[i];
		i++;
		k++;
	}
	dst[k] = '\0';
	return (dst);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_exit(t_data *data)
{
	free_destroy(data, 1);
	return (0);
}
