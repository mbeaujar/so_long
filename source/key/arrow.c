/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:01:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 13:48:10 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(t_game *game, char c)
{
	if (game->collectible > 0 && c == 'E')
		return (0);
	if (c == '0' || c == 'C' || c == 'E' || c == 'N')
		return (1);
	return (0);
}

void	keybackward(int keycode, t_game *game)
{
	(void)keycode;
	if (game->posx + 1 < game->lenx
		&& is_valid(game, game->map[game->posx + 1][game->posy]))
	{
		if (game->map[game->posx + 1][game->posy] == 'C')
			game->collectible--;
		if (game->map[game->posx + 1][game->posy] == 'E')
			quit_the_game(game);
		if (game->map[game->posx + 1][game->posy] == 'N')
			quit_the_game(game);
		game->map[game->posx][game->posy] = '0';
		game->map[game->posx + 1][game->posy] = 'P';
		game->posx++;
		game->move++;
	}
}

void	keyforward(int keycode, t_game *game)
{
	(void)keycode;
	if (game->posx - 1 > 0
		&& is_valid(game, game->map[game->posx - 1][game->posy]))
	{
		if (game->map[game->posx - 1][game->posy] == 'C')
			game->collectible--;
		if (game->map[game->posx - 1][game->posy] == 'E')
			quit_the_game(game);
		if (game->map[game->posx - 1][game->posy] == 'N')
			quit_the_game(game);
		game->map[game->posx][game->posy] = '0';
		game->map[game->posx - 1][game->posy] = 'P';
		game->posx--;
		game->move++;
	}
}

void	keyleft(int keycode, t_game *game)
{
	(void)keycode;
	if (game->posy - 1 > 0
		&& is_valid(game, game->map[game->posx][game->posy - 1]))
	{
		if (game->map[game->posx][game->posy - 1] == 'C')
			game->collectible--;
		if (game->map[game->posx][game->posy - 1] == 'E')
			quit_the_game(game);
		if (game->map[game->posx][game->posy - 1] == 'N')
			quit_the_game(game);
		game->map[game->posx][game->posy] = '0';
		game->map[game->posx][game->posy - 1] = 'P';
		game->posy--;
		game->move++;
	}
}

void	keyright(int keycode, t_game *game)
{
	(void)keycode;
	if (game->posy + 1 < game->leny
		&& is_valid(game, game->map[game->posx][game->posy + 1]))
	{
		if (game->map[game->posx][game->posy + 1] == 'C')
			game->collectible--;
		if (game->map[game->posx][game->posy + 1] == 'E')
			quit_the_game(game);
		if (game->map[game->posx][game->posy + 1] == 'N')
			quit_the_game(game);
		game->map[game->posx][game->posy] = '0';
		game->map[game->posx][game->posy + 1] = 'P';
		game->posy++;
		game->move++;
	}
}
