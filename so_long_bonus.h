/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:47 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/17 18:25:32 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*imgx;
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
	int		player_dead;
}	t_data;

int		ft_strlen_t(char *string);
void	check_map(int fd, int *w, int *I);
void	check_lastline_bonus(char **map, int row);
char	**get_map(int fd, int w);
char	*ft_memcpy(char *src, char *dst);
int		draw_map(t_data *data);
void	start_game(t_data *data, char *filename);
int		handel_key(int key, t_data *data);
void	place_p_bonus(t_data *data);
void	count_x(char **map, int row, int *x);
void	check_pathmain(t_data *data);
int		animation(t_data *data);
int		animated_lose(t_data *data);
void	animated_enemy(t_data *data);
void	moving_enemy(t_data *data);
void	ft_draw(t_data *d, char c, void *img, void *imgb);
void	*ft_memset(void *b, int c, size_t len);
void	free_destroy(t_data *data, int x);
void	calculate_moves_bonus(t_data *data, int move);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_exit(t_data *data);

#endif
