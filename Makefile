NAME = so_long
SRCS = kek.c is_valid_map.c get_next_line.c ft_strchr.c ft_strjoin.c ft_strlen.c\
		get_params.c check_input.c get_map.c ft_strlcpy.c startuem.c vortex.c collect.c\
		drow_walls.c drow_background.c meditate.c enemy_idle.c drow.c get_obj.c find_player.c\
		what_to_do.c find_collects.c drow_steps.c ft_itoa.c enemy_moves.c check_other_help.c\

OBJS = $(SRCS:%.c=%.o)
HEADERX = MinilibX/mlx.h
CC=gcc
RM = rm -f

$(NAME): $(OBJS) 
	$(CC) $(OBJS) -I $(HEADERX) -lmlx -framework OpenGL -framework AppKit libmlx.a -o $(NAME)

all		:	$(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all