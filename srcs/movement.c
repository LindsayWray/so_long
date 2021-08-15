/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:59:34 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:59:35 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moving(t_mapstruct *map, int y, int x)
{
	t_field	next_field;

	next_field = map->fields[y][x];
	if (next_field == EMPTY || next_field == COLLECTIBLE)
	{
		map->fields[map->player.y][map->player.x] = EMPTY;
		map->fields[y][x] = PLAYER;
		map->player.y = y;
		map->player.x = x;
		if (next_field == COLLECTIBLE)
			map->collectible--;
		map->step_count++;
		render_map(*map);
	}
	if (next_field == ENEMY)
		pop_up_window(map, 520, "You Lose", map->images.lose);
	if (next_field == EXIT && map->collectible == 0)
		pop_up_window(map, 630, "You Win", map->images.win);
}

void	movement(t_mapstruct *map, t_movement move)
{
	if (move == MOVE_UP)
		moving(map, map->player.y - 1, map->player.x);
	if (move == MOVE_DOWN)
		moving(map, map->player.y + 1, map->player.x);
	if (move == MOVE_LEFT)
		moving(map, map->player.y, map->player.x - 1);
	if (move == MOVE_RIGHT)
		moving(map, map->player.y, map->player.x + 1);
}
