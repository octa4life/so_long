/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:52:05 by octavie           #+#    #+#             */
/*   Updated: 2025/05/07 10:21:09 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_background(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall)
				print_img(data, data->img.img_wall, i, y);
			if (data->map[y][i] == data->content.space)
				print_img(data, data->img.img_floor, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}
//draws the wall and floor images on the window based on the map layout.

void	display_other(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				print_img(data, data->img.img_collect, i, y);
			if (data->map[y][i] == data->content.player)
			{
				data->pos.x = i * data->img.width;
				data->pos.y = y * data->img.height;
				print_img(data, data->img.img_player, i, y);
			}
			if (data->map[y][i] == data->content.exit)
				print_img(data, data->img.img_exit, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}
// renders the collectibles, player,
// and exit images and updates the player's pixel position.

int	display(t_data *data)
{
	display_background(data);
	display_other(data);
	return (0);
}
//calls the background and other display functions to draw the full map.

void	core_display(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width), (data->height * data->img.height),
			"So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &display, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &finish, data);
	mlx_loop(data->mlx_ptr);
	finish(data);
}
//initializes the window and sets up
// the rendering and event loop for the game.

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}
//places an image at the specified tile coordinates on the game window.
