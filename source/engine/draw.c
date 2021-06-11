/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:19:09 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/11 19:24:27 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    my_mlx_pixel_put(int x, int y, t_game *game, unsigned int color)
{
    char    *pixel;

    if (y >= game->resolutiony)
        return ;
    if (x >= game->resolutionx)
        return ;
    pixel = (game->addr + (4 * game->resolutionx * y) + (4 * x));
    *(unsigned int*)pixel = color;
}

/* void	my_mlx_pixel_put(int x, int y, t_game *game, unsigned int color)
{
	char *dst;

	dst = game->addr + (y * game->sl + x * (game->bpp / 8));
	*(unsigned int *)dst = color;
}
 */
void calcule_len_squarre(t_game *game)
{
    game->sq_lenx = game->resolutionx / game->leny;
    game->sq_leny = game->resolutiony / game->lenx;
}

void draw_squarre(t_game *game, int i, int j)
{
    int x;
    int y;
    unsigned int color;

    x = 0;
    while (x < game->sq_lenx)
    {
        y = 0;
        while (y < game->sq_leny)
        {
            if (x == 0 && j > 0 && game->map[i][j - 1] != game->map[i][j])
                color = 0x000000;
            else if (x == game->sq_lenx - 1 && j + 1 < game->leny && game->map[i][j + 1] != game->map[i][j])
                color = 0x000000;
            else if (y == 0 && i > 0 && game->map[i - 1][j] != game->map[i][j])
                color = 0x000000;
            else if (y == game->sq_leny - 1 && i + 1 < game->lenx && game->map[i + 1][j] != game->map[i][j])
                color = 0x000000;
            else
            {
                if (game->map[i][j] == '1')
                    color = 0xFF0000;
                else
                    color = 0xFFFFFF;
            }
            my_mlx_pixel_put((j * game->sq_lenx) + x, (i * game->sq_leny) + y, game, color);
            y++;
        }
        x++;
    }
}

void draw_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            draw_squarre(game, i, j);
            j++;
        }
        i++;
    }
}