/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:01:04 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/11 14:54:40 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    keyforward(int keycode, t_game *game)
{
    (void)keycode;
    if (game->posx + 1 < game->lenx)
        game->posx++;
}

void keybackward(int keycode, t_game *game)
{
    (void)keycode;
    if (game->posx - 1 > 0)
        game->posx--;
}

void keyleft(int keycode, t_game *game)
{
    (void)keycode;
    if (game->posy - 1 > 0)
        game->posy--;
}

void keyright(int keycode, t_game *game)
{
    (void)keycode;
    if (game->posy + 1 < game->leny)
        game->posy--;
}

