/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:42:19 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/15 01:17:36 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_draw(t_data *d, char c, void *img, void *imgb)
{
	int	ww;
	int	i;

	i = 0;
	ww = 0;
	d->posy = 0;
	d->posx = 0;
	while (ww != d->w)
	{
		d->posy = 0;
		while (d->map[ww][i])
		{
			if (d->map[ww][i] == c)
				mlx_put_image_to_window(d->mlx, d->win, img, d->posy, d->posx);
			if (d->map[ww][i] == '0')
				mlx_put_image_to_window(d->mlx, d->win, imgb, d->posy, d->posx);
			d->posy = d->posy + 50;
			i++;
		}
		d->posx = d->posx + 50;
		i = 0;
		ww++;
	}
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
