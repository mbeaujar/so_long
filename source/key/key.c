/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:29:06 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 15:37:52 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_the_game(t_game *game)
{
	free_tab(game->map);
	mlx_destroy_image(game->mlx, game->exit.text);
	mlx_destroy_image(game->mlx, game->collec.text);
	mlx_destroy_image(game->mlx, game->minion[0].text);
	mlx_destroy_image(game->mlx, game->minion[1].text);
	mlx_destroy_image(game->mlx, game->enemy.text);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (1);
}

int	clear_key(int key, t_game *game)
{
	(void)key;
	game->anim = 0;
	return (1);
}

int	key(int keycode, t_game *game)
{
	if (keycode == FORWARD || keycode == BACKWARD
		|| keycode == LEFT || keycode == RIGHT)
		game->anim = 1;
	if (keycode == FORWARD)
		keyforward(keycode, game);
	if (keycode == BACKWARD)
		keybackward(keycode, game);
	if (keycode == LEFT)
		keyleft(keycode, game);
	if (keycode == RIGHT)
		keyright(keycode, game);
	if (keycode == ESC)
		quit_the_game(game);
	return (1);
}
