/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:28:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/12 20:24:58 by mbeaujar         ###   ########.fr       */
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