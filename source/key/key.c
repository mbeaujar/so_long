/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:15:20 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/14 13:44:24 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int quit_the_game(t_game *game)
{
    (void)game;
    //free_tab(game->map);
    exit(0);
    return (1);
}

int clear_key(int key, t_game *game)
{
    (void)key;
    game->anim = 0;
    return (1);
}

int key(int keycode, t_game *game)
{
    if (keycode == FORWARD || keycode == BACKWARD || keycode == LEFT || keycode == RIGHT)
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