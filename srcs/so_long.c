/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:59:01 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:59:03 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list		*list;
	t_mapstruct	map;

	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong amount of arguments\n", STDERR_FILENO);
		return (0);
	}
	map = parse_map(argv[1], &list);
	create_fields(&map, &list);
	map.mlx = mlx_init();
	if (!map.mlx)
		mlx_error(map.fields, map.height);
	map.mlx_win = mlx_new_window(map.mlx, 48 * map.width, 48 * map.height,
			"So long and thanks for all the catnip");
	if (!map.mlx_win)
		mlx_error(map.fields, map.height);
	map.images = png_to_mlx(map);
	render_map(map);
	mlx_key_hook(map.mlx_win, key_hook, &map);
	mlx_hook(map.mlx_win, 17, 1L << 17, close_window, &map);
	mlx_loop(map.mlx);
	return (0);
}
