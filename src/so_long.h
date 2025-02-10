/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:47 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/10 14:00:26 by obellil-         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct img_s
{
	void	*img_floor;
	void	*img_p;
	void	*img_e;
	void	*img_wall;
	void	*img_c;
	int		height;
	int		width;
	char	*p;
	char	*floor;
	char	*wall;
	char	*c;
	char	*e;
}				t_img;

typedef struct cnt_s
{
	char	e;
	char	c;
	char	p;
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


// Parsing
void	print_error(void);
int		main(int argc, char **argv);
int		openfd(char **argv);
int		gnlfd(char **argv);
int		check_close(char **argv);
int		check_obj(char **argv);
int		floodfill(char **tab, t_pos y, t_pos x);
void	ff(char **tab, int x, int y);
#endif
