/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:47 by obellil-          #+#    #+#             */
/*   Updated: 2025/05/05 10:44:12 by octavie          ###   ########.fr       */
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
//# include <X11/keysym.h>
//# include <X11/X.h>
# include <fcntl.h>
# include "../libft/libft.h"
//# include "../minilibx-linux/mlx.h"

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

int		ft_strchr(char *str, char *cmp);// a mettre dans la libft
void	*print_error(char *str);
int		ft_same_char(char *str);

char	*get_map(int fd);
char	**map_check(char **str, t_data *data);
int		checker_map(char **argv);

int		check_col(char *map_line, char col, t_data *data);
int		check_line(char *map_line, char wall);
int		check_other(char *map_line, t_cnt *content);
void	check_content(t_data *data);
int		check_format(char **map);
int		check_collectible(t_data *data);

void	set_img(t_data *data);
void	set_obj(t_cnt *content);

void	core_display(t_data *data);
int		display(t_data *data);
void	display_other(t_data *data);
void	display_background(t_data *data);
void	mouv_down(t_data *data);
void	mouv_left(t_data *data);
void	mouv_right(t_data *data);
void	mouv_top(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

int		key_press(int keysym, t_data *data);
int		end(t_data *data);

#endif