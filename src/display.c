/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octavie <octavie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:52:05 by octavie           #+#    #+#             */
/*   Updated: 2025/05/05 10:28:26 by octavie          ###   ########.fr       */
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

int	display(t_data *data)
{
	display_background(data);
	display_other(data);
	return (0);
}

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
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}