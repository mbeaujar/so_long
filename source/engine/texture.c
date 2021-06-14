/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:28:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 12:08:08 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void open_texture_exit(t_game *game)
{
	game->exit.text = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &game->exit.width, &game->exit.height);
	if (game->exit.text == NULL)
		return ;
	game->exit.addr = mlx_get_data_addr(game->exit.text, &game->exit.bpp, &game->exit.sl, &game->exit.ed);
}

void open_texture_collec(t_game *game)
{
	game->collec.text = mlx_xpm_file_to_image(game->mlx, "./textures/collectible.xpm", &game->collec.width, &game->collec.height);
	if (game->collec.text == NULL)
		return ;
	game->collec.addr = mlx_get_data_addr(game->collec.text, &game->collec.bpp, &game->collec.sl, &game->collec.ed);
}

void open_texture_minion(t_game *game, int i, char *path)
{
	game->minion[i].text = mlx_xpm_file_to_image(game->mlx, path, &game->minion[i].width, &game->minion[i].height);
	if (game->minion[i].text == NULL)
		return ;
	game->minion[i].addr = mlx_get_data_addr(game->minion[i].text, &game->minion[i].bpp, &game->minion[i].sl, &game->minion[i].ed);
}

void open_texture_enemy(t_game *game)
{
	game->enemy.text = mlx_xpm_file_to_image(game->mlx, "./textures/enemy.xpm", &game->enemy.width, &game->enemy.height);
	if (game->enemy.text == NULL)
		return ;
	game->enemy.addr = mlx_get_data_addr(game->enemy.text, &game->enemy.bpp, &game->enemy.sl, &game->enemy.ed);
}
