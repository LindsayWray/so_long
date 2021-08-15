/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:58:46 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:58:48 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_list *list, int width)
{
	char	*content;

	content = list->content;
	while (*content)
	{
		if (*content != '1')
			return (0);
		content++;
	}
	while (list->next)
	{
		content = list->content;
		if (content[0] != '1' || content[width - 1] != '1')
			return (0);
		list = list->next;
	}
	content = list->content;
	while (*content)
	{
		if (*content != '1')
			return (0);
		content++;
	}
	return (1);
}

int	check_width(t_list *list)
{
	int	len_first_line;
	int	len;

	len_first_line = ft_strlen(list->content);
	if (len_first_line < 3)
		return (0);
	while (list)
	{
		len = ft_strlen(list->content);
		if (len != len_first_line)
			return (0);
		list = list->next;
	}
	return (len_first_line);
}

void	read_map(char *txt, t_list **list)
{
	char	*line;
	t_list	*newest;
	int		fd;
	int		continue_reading;

	if (!ends_with(txt, ".ber"))
		file_error("file extension must be .ber\n" );
	fd = open(txt, O_RDONLY);
	if (fd == -1)
		file_error("input file does not exist\n");
	line = NULL;
	continue_reading = 1;
	while (continue_reading)
	{
		continue_reading = get_next_line(fd, &line);
		if (continue_reading == -1)
			malloc_error(list);
		newest = ft_lstnew(line);
		if (!newest)
			malloc_error(list);
		ft_lstadd_back(list, newest);
	}
}

t_mapstruct	parse_map(char *txt, t_list **list)
{
	t_mapstruct	map;

	*list = NULL;
	read_map(txt, list);
	map.width = check_width(*list);
	if (!map.width)
		parsing_error(list);
	map.height = ft_lstsize(*list);
	if (!check_walls(*list, map.width))
		parsing_error(list);
	if (!check_input(*list, &map))
		parsing_error(list);
	map.step_count = 0;
	return (map);
}
