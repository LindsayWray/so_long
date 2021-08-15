/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/15 16:59:06 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/15 16:59:08 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h> 
# include "../libft/libft.h"

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define BACKGROUND 0x00ACC3AF

typedef enum s_field
{
	EMPTY,
	WALL,
	PLAYER,
	COLLECTIBLE,
	ENEMY,
	EXIT
}		t_field;

typedef enum s_movement
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
}	t_movement;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_images
{
	void	*cat;
	void	*wall;
	void	*catnip;
	void	*vacuum;
	void	*exit;
	void	*lose;
	void	*win;
}		t_images;

typedef struct s_mapstruct
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	int			collectible;
	int			step_count;
	t_position	player;
	t_field		**fields;
	t_images	images;
}		t_mapstruct;

t_mapstruct	parse_map(char *txt, t_list **list);
t_images	png_to_mlx(t_mapstruct map);
void		parsing_error(t_list **list);
void		malloc_error(t_list **list);
void		mlx_error(t_field **fields, int len);
void		malloc_error_map(t_list **list, t_field **fields, int len);
void		file_error(char *error_message);
void		create_fields(t_mapstruct *map, t_list **list);
void		render_map(t_mapstruct map);
void		movement(t_mapstruct *map, t_movement move);
void		free_fields(t_field	**fields, int len);
void		free_images(t_images images, void *mlx);
int			close_window(t_mapstruct *map);
void		display_steps(t_mapstruct map);
int			check_input(t_list *list, t_mapstruct *map);
void		pop_up_window(t_mapstruct *map, int size, char *title, void *image);
int			key_hook(int keycode, t_mapstruct *map);

#endif
