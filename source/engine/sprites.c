/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:24:13 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 16:00:35 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_texture(t_game *game, int i, int j, t_image img)
{
	int		x;
	int		y;
	int		txt_x;
	int		txt_y;
	char	*color;

	x = 0;
	while (x < game->sq_lenx)
	{
		y = 0;
		while (y < game->sq_leny)
		{
			txt_x = img.width / (100 / (((double)x / game->sq_lenx) * 100.0));
			txt_y = img.height / (100 / (((double)y / game->sq_leny) * 100.0));
			color = img.addr + ((4 * img.width * txt_y) + (4 * txt_x));
			if (*(unsigned int *)color != NONE)
				my_mlx_pixel_put((j * game->sq_lenx) + x,
					(i * game->sq_leny) + y, game, *(unsigned int *)color);
			else
				my_mlx_pixel_put((j * game->sq_lenx) + x,
					(i * game->sq_leny) + y, game, 0xFFFFFF);
			y++;
		}
		x++;
	}
}
