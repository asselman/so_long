/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:47 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 18:26:32 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./GNL/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "mlx.h"
# include "stdlib.h"

typedef struct so_long
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*imgb;
	void	*imgp;
	void	*imgcoin;
	void	*imgdoor;
	char	**map;
	char	**fakemap;
	int		**pos_x;
	int		en;
	int		y;
	int		x;
	int		w;
	int		len;
	int		coin;
	int		pc;
	int		line;
	int		index;
	int		posx;
	int		posy;
}	t_data;

int		ft_strlen_t(char *string);
void	check_map(int fd, int *w, int *I);
void	check_lastline(char **map, int row);
char	**get_map(int fd, int w);
char	*ft_memcpy(char *src, char *dst);
int		draw_map(t_data *data);
int		handel_key(int key, t_data *data);
void	start_game(t_data *data, char *filename);
void	place_p(t_data *data);
void	check_pathmain(t_data *data);
void	*ft_memset(void *b, int c, size_t len);
void	free_destroy(t_data *data, int x);
void	ft_putstr_fd(char *s, int fd);
int		ft_exit(t_data *data);

#endif
