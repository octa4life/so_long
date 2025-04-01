/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:47 by obellil-          #+#    #+#             */
/*   Updated: 2025/04/01 11:14:51 by obellil-         ###   ########.fr       */
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

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct data_s
{
	char	**map;
}				t_data;


// Parsing
int		main(int argc, char **argv);
int		openfd(char **argv);
int		gnlfd(char **argv);
int		check_close(char **argv);
int		check_obj(char **argv);
int		floodfill(char **tab, t_pos y, t_pos x);
void	ff(char **tab, int x, int y);
char	**fill_map(char **argv);
char	**copy_tab(char **tab);
int		check_square_map(char **map);

//Utils
int		print_error(char *mess);
int		get_line_length(char *line);
void	init_struct(t_data *data, char **argv);

#endif
