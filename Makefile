# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwray <lwray@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/26 08:01:17 by lwray         #+#    #+#                  #
#    Updated: 2021/07/26 14:44:32 by lwray         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := so_long
HEADERFILES := srcs/so_long.h
SO_LONG_SRCS :=		srcs/display_steps.c \
					srcs/check_input.c
SO_LONG_BONUS :=	srcs/bonus/display_steps_bonus.c \
					srcs/bonus/check_input_bonus.c
SHARED_SRCS :=		srcs/so_long.c \
					srcs/parsing.c \
					srcs/cleanup.c \
					srcs/error_handler.c \
					srcs/create_fields.c \
					srcs/render_map.c \
					srcs/movement.c \
					srcs/png_to_mlx.c \
					srcs/events.c

FLAGS := -Wall -Wextra -Werror -Imlx -g
OBJFILES := $(SO_LONG_SRCS:srcs/%.c=obj/%.o) $(SHARED_SRCS:srcs/%.c=obj/%.o)
BONUS_OBJ := $(SO_LONG_BONUS:srcs/%.c=obj/%.o) $(SHARED_SRCS:srcs/%.c=obj/%.o)
LIBFT := libft/
MLX := mlx/

all: $(NAME)

$(NAME): $(OBJFILES) 
	@make -C $(LIBFT)
	@make -C $(MLX)
	cp $(MLX)libmlx.dylib .
	gcc -o $@ $^ -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lz

bonus: $(BONUS_OBJ)
	@make -C $(LIBFT)
	@make -C $(MLX)
	cp $(MLX)libmlx.dylib .
	gcc -o $(NAME) $^ -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lz

obj/%.o: srcs/%.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJFILES)
	@make fclean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SO_LONG_SRCS) $(SHARED_SRCS) $(SO_LONG_BONUS) $(HEADERFILES)
	make norm -C $(LIBFT)

.PHONY: all clean fclean re norm bonus
