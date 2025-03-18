/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:47 by obellil-          #+#    #+#             */
/*   Updated: 2025/03/18 12:03:27 by obellil-         ###   ########.fr       */
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

typedef struct infra_s
{
	char	**map;
	int		x;
	int		y;
}				t_infra;

// typedef struct data_s
// {
// 	int		data;

// }				t_data;

// Parsing
int		main(int argc, char **argv);
int		openfd(char **argv);
int		gnlfd(char **argv);
int		check_close(char **argv);
int		check_obj(char **argv);
int		floodfill(char **tab, t_infra y, t_infra x);
void	ff(char **tab, int x, int y);
void	init_struct(t_infra *data, char **argv);
char	**fill_map(char **argv);
char	**copy_tab(char **tab);

//Utils
void	print_error(void);

#endif
