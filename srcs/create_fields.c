/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_fields.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:59:21 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:59:23 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_row(char *content, t_field **fields, int i,
	t_position *player_position)
{
	int	j;

	j = 0;
	while (content[j])
	{
		if (content[j] == '0')
			fields[i][j] = EMPTY;
		else if (content[j] == '1')
			fields[i][j] = WALL;
		else if (content[j] == 'C')
			fields[i][j] = COLLECTIBLE;
		else if (content[j] == 'E')
			fields[i][j] = EXIT;
		else if (content[j] == 'V')
			fields[i][j] = ENEMY;
		else if (content[j] == 'P')
		{
			fields[i][j] = PLAYER;
			player_position->x = j;
			player_position->y = i;
		}
		j++;
	}
}

static t_position	fill_fields(t_field **fields, t_list *list)
{
	int			i;
	t_position	player_position;

	i = 0;
	while (list)
	{
		fill_row(list->content, fields, i, &player_position);
		i++;
		list = list->next;
	}
	return (player_position);
}

void	create_fields(t_mapstruct *map, t_list **list)
{
	int	i;

	map->fields = (t_field **)malloc(map->height * sizeof (t_field *));
	if (!map->fields)
		malloc_error(list);
	i = 0;
	while (i < map->height)
	{
		map->fields[i] = (t_field *)malloc(map->width * sizeof(t_field));
		if (!map->fields[i])
			malloc_error_map(list, map->fields, i);
		i++;
	}
	map->player = fill_fields(map->fields, *list);
	ft_lstclear(list);
}
