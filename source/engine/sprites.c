/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:24:13 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/12 20:25:53 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void draw_exit(t_game *game, int i, int j)
{
	int	x;
	int	y;
	int txt_x;
	int txt_y;
	char			*color;

	x = 0;
	while (x < game->sq_lenx)
	{
		y = 0;
		while (y < game->sq_leny)
		{
			txt_x = game->exit.width / (100 / ((double)((double)x / (double)game->sq_lenx) * 100.0));
			txt_y = game->exit.height / (100 / ((double)((double)y / (double)game->sq_leny) * 100.0));
			color = game->exit.addr + ((4 * game->exit.width * txt_y) + (4 * txt_x));
			if (*(unsigned int *)color != NONE)
				my_mlx_pixel_put((j * game->sq_lenx) + x, (i * game->sq_leny) + y, game, *(unsigned int *)color);
			else
				my_mlx_pixel_put((j * game->sq_lenx) + x, (i * game->sq_leny) + y, game, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

void draw_apple(t_game *game, int i, int j)
{
	int	x;
	int	y;
	int txt_x;
	int txt_y;
	char			*color;

	x = 0;
	while (x < game->sq_lenx)
	{
		y = 0;
		while (y < game->sq_leny)
		{
			txt_x = game->collec.width / (100 / ((double)((double)x / (double)game->sq_lenx) * 100.0));
			txt_y = game->collec.height / (100 / ((double)((double)y / (double)game->sq_leny) * 100.0));
			color = game->collec.addr + ((4 * game->collec.width * txt_y) + (4 * txt_x));
			if (*(unsigned int *)color != NONE)
				my_mlx_pixel_put((j * game->sq_lenx) + x, (i * game->sq_leny) + y, game, *(unsigned int *)color);
			else
				my_mlx_pixel_put((j * game->sq_lenx) + x, (i * game->sq_leny) + y, game, 0xFFFFFF);
			y++;
		}
		x++;
	}
}
