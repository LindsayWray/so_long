/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:58:39 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:58:41 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mapstruct *map)
{
	if (keycode == ESC_KEY)
		close_window(map);
	if (keycode == W_KEY)
		movement(map, MOVE_UP);
	if (keycode == A_KEY)
		movement(map, MOVE_LEFT);
	if (keycode == S_KEY)
		movement(map, MOVE_DOWN);
	if (keycode == D_KEY)
		movement(map, MOVE_RIGHT);
	return (0);
}

int	close_window(t_mapstruct *map)
{
	free_fields(map->fields, map->height);
	free_images(map->images, map->mlx);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(EXIT_SUCCESS);
}

static int	esc_hook(int keycode, t_mapstruct *map)
{
	if (keycode == ESC_KEY)
		close_window(map);
	return (0);
}

void	pop_up_window(t_mapstruct *map, int size, char *title, void *image)
{
	mlx_destroy_window (map->mlx, map->mlx_win);
	map->mlx_win = mlx_new_window(map->mlx, size, size, title);
	mlx_put_image_to_window(map->mlx, map->mlx_win, image, 0, 0);
	mlx_key_hook(map->mlx_win, esc_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 17, close_window, map);
}
