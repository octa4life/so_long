/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:42:47 by obellil-          #+#    #+#             */
/*   Updated: 2025/02/11 13:52:50 by obellil-         ###   ########.fr       */
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

// Parsing
int		main(int argc, char **argv);
int		openfd(char **argv);
int		gnlfd(char **argv);
int		check_close(char **argv);
int		check_obj(char **argv);
int		floodfill(char **tab, t_pos y, t_pos x);
void	ff(char **tab, int x, int y);
void	init_struct(t_pos data, char *filename);
char	**fill_map(char **argv);

//Utils
void	print_error(void);

#endif
