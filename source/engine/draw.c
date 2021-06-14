/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:19:09 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 15:46:17 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(int x, int y, t_game *game, unsigned int color)
{
	char	*pixel;

	if (y >= game->resolutiony)
		return ;
	if (x >= game->resolutionx)
		return ;
	pixel = (game->addr + (4 * game->resolutionx * y) + (4 * x));
	*(unsigned int *)pixel = color;
}

void	calcule_len_squarre(t_game *game)
{
	game->sq_lenx = (game->resolutionx / game->leny) + 1;
	game->sq_leny = (game->resolutiony / game->lenx) + 1;
}

int	which_rgb(t_game *game, int i, int j, int pos[2])
{
	if (pos[0] == 0 && j > 0 && game->map[i][j - 1] != game->map[i][j])
		return (0x000000);
	else if (pos[0] == game->sq_lenx - 1 && j + 1 < game->leny
		&& game->map[i][j + 1] != game->map[i][j])
		return (0x000000);
	else if (pos[1] == 0 && i > 0 && game->map[i - 1][j] != game->map[i][j])
		return (0x000000);
	else if (pos[1] == game->sq_leny - 1 && i + 1 < game->lenx
		&& game->map[i + 1][j] != game->map[i][j])
		return (0x000000);
	else
	{
		if (game->map[i][j] == '1')
			return (0x754F46);
		else if (game->map[i][j] == '0')
			return (0xFFFFFF);
	}
}

void	draw_squarre(t_game *game, int i, int j)
{
	int	pos[2];
	int	color;

	pos[0] = 0;
	while (pos[0] < game->sq_lenx)
	{
		pos[1] = 0;
		while (pos[1] < game->sq_leny)
		{
			color = which_rgb(game, i, j, pos);
			my_mlx_pixel_put((j * game->sq_lenx) + pos[0],
				(i * game->sq_leny) + pos[1], game, color);
			pos[1]++;
		}
		pos[0]++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				draw_texture(game, i, j, game->exit);
			else if (game->map[i][j] == 'C')
				draw_texture(game, i, j, game->collec);
			else if (game->map[i][j] == 'P')
				draw_texture(game, i, j, game->minion[game->anim]);
			else if (game->map[i][j] == 'N')
				draw_texture(game, i, j, game->enemy);
			else
				draw_squarre(game, i, j);
			j++;
		}
		i++;
	}
}
