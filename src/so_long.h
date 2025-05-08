/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:47 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/08 10:45:35 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define ERROR_C_E "Error : Not all collectibles or exit reachable\n"
# define ERROR_LINE "Error : Empty line in your map \n"

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}				t_data;

// utils
void	*print_error(char *str);
int		only_ones(char *str);
void	*free_map(t_data *data);
int		get_next_line(int fd, char **str);
char	*ft_stradd(char *str, char buff);

//init
char	*get_map(int fd);
char	**map_core(char **str, t_data *data);

//checking
int		check_wall(char *map_line, char col, t_data *data);
int		check_line(char *map_line, char wall);
int		check_other(char *map_line, t_cnt *content);
void	check_content(t_data *data);
int		check_square(char **map);
int		get_collectible_count(t_data *data);

// set
void	set_img(t_data *data);
void	set_content(t_cnt *content);

//display & mouv
void	core_display(t_data *data);
int		display(t_data *data);
void	display_other(t_data *data);
void	display_background(t_data *data);
void	mouv_down(t_data *data);
void	mouv_left(t_data *data);
void	mouv_right(t_data *data);
void	mouv_top(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

//floodfill
void	free_map_array(char **map);
char	**dup_map(char **map);
int		check_reachability(t_data *data);
void	flood_fill(char **map, int x, int y);
int		find_player_pos(char **map, int *x, int *y);

// other
int		key_press(int keysym, t_data *data);
int		finish(t_data *data);

#endif
