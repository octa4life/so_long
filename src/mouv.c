/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obellil- <obellil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:53:02 by octavie           #+#    #+#             */
/*   Updated: 2025/05/07 16:57:17 by obellil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouv_top(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (get_collectible_count(data) == 0)
			{
				printf("GG WL BRO  tu as win en : %d coup(s) !\n",
					data->count);
				finish(data);
			}
		}
	}
}
// moves the player up if the tile above is not a wall,
// handles collectibles, and checks for a win at the exit.

void	mouv_right(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (get_collectible_count(data) == 0)
			{
				printf("GG WL BRO  tu as win en : %d coup(s) !\n",
					data->count);
				finish(data);
			}
		}
	}
}
// moves the player right if the tile to the right is not a wall,
// handles collectibles, and checks for a win at the exit.

void	mouv_left(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (get_collectible_count(data) == 0)
			{
				printf("GG WL BRO  tu as win en : %d coup(s) !\n",
					data->count);
				finish(data);
			}
		}
	}
}
// moves the player left if the tile to the left is not a wall,
//  handles collectibles, and checks for a win at the exit.

void	mouv_down(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (get_collectible_count(data) == 0)
			{
				printf("GG WL BRO  tu as win en : %d coup(s) !\n",
					data->count);
				finish(data);
			}
		}
	}
}
// moves the player down if the tile below is not a wall,
// handles collectibles, and checks for a win at the exit.
