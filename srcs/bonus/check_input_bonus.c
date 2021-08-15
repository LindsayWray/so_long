/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:58:03 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:58:07 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_content(char *content, int *exit, int *player, t_mapstruct *map)
{
	while (*content)
	{
		if (*content != '1' && *content != '0' && *content != 'E'
			&& *content != 'P' && *content != 'C' && *content != 'V')
			return (0);
		if (*content == 'E')
			(*exit)++;
		if (*content == 'C')
			map->collectible++;
		if (*content == 'P')
			(*player)++;
		content++;
	}
	return (1);
}

int	check_input(t_list *list, t_mapstruct *map)
{
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	map->collectible = 0;
	while (list)
	{
		if (!check_content(list->content, &exit, &player, map))
			return (0);
		list = list->next;
	}
	if (player != 1 || exit < 1 || map->collectible < 1)
		return (0);
	return (1);
}
