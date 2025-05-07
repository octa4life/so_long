/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:22:36 by octavie           #+#    #+#             */
/*   Updated: 2025/05/07 15:36:24 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_content(t_cnt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}
// initializes the map symbols and related counters for player,
// exit, wall, space, and collectible.

void	set_img(t_data *data)
{
	data->img.height = 64;
	data->img.width = 64;
	data->img.floor = "./textures/floor.xpm";
	data->img.wall = "./textures/wall.xpm";
	data->img.collect = "./textures/chest.xpm";
	data->img.player = "./textures/bats.xpm";
	data->img.exit = "./textures/door.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}
// sets the file paths and loads the images for all game textures
// (wall, floor, player, collectible, exit).

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		finish(data);
	if (keysym == XK_w)
		mouv_top(data);
	if (keysym == XK_d)
		mouv_right(data);
	if (keysym == XK_a)
		mouv_left(data);
	if (keysym == XK_s)
		mouv_down(data);
	return (0);
}
// handles key inputs for player movement and quitting the game.

int	get_collectible_count(t_data *data)
{
	int		i;
	int		y;
	int		count;

	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}
//counts the number of remaining collectibles on the map.

int	finish(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
//  frees all allocated memory, destroys images and the window,
// and safely exits the game.
