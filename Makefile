# Created Ayoub Bablil && Achraf Laalalma

# NAME
NAME = cub3D

# CC
CC = cc

# HEADERS
MAIN_HEADERS = cub3D.h includes.h
MANDATORY_HEADERS = Mandatory/parsing/parsing.h Mandatory/execution/execution.h Mandatory/utils/utils.h 
BONUS_HEADERS = Bonus/execution/execution_bonus.h Bonus/parsing/parsing_bonus.h Bonus/utils/utils.h
UTILS_HEADERS = libs/get_next_line/get_next_line.h libs/libft/libft.h

M_HEADERS = $(MAIN_HEADERS) $(UTILS_HEADERS) $(MANDATORY_HEADERS)
B_HEADERS = $(MAIN_HEADERS) $(UTILS_HEADERS) $(BONUS_HEADERS)

# FLAGS
CFLAGS = -Wall -Wextra -Werror

# LIBRARIES
LIBFT = libs/libft/libft.a
GNL = libs/get_next_line/get_next_line.c libs/get_next_line/get_next_line_utils.c

#mlx
MLX = -lmlx -framework OpenGL -framework AppKit

#******************** MANDATORY ********************

# SOURCES
RENDERING = renderwall.c
MOVEMENT = movement.c player.c
DRAW = draw.c pixels.c
RAYCASTING = raycasting.c wallhits.c
UTILS_EXEC = utils.c
UTILS_2 = errors.c free.c tools.c
PARSING = parsing.c checking.c converting.c map.c more_checking.c reading.c textures.c xpm.c colors.c
EXEC = execution.c $(addprefix rendering/, $(RENDERING)) $(addprefix movement/, $(MOVEMENT)) $(addprefix utils/, $(UTILS_EXEC)) $(addprefix draw/, $(DRAW)) $(addprefix raycasting/, $(RAYCASTING))
MANDATORY = main.c $(addprefix parsing/, $(PARSING)) $(addprefix execution/, $(EXEC)) $(addprefix utils/, $(UTILS_2))


#********************* BONUS **********************

# SOURCES
RENDERING_BONUS = renderwall_bonus.c rendering_bonus.c rendertorch_bonus.c
MOVEMENT_BONUS = movement_bonus.c player_bonus.c
DRAW_BONUS = draw_bonus.c pixels_bonus.c
RAYCASTING_BONUS = raycasting_bonus.c wallhits_bonus.c
UTILS_EXEC_BONUS = utils_bonus.c doors_bonus.c doors_list_bonus.c
UTILS_BONUS = errors.c free.c tools.c more_free.c
PARSING_BONUS = checking_bonus.c converting_bonus.c map_bonus.c more_checking_bonus.c reading_bonus.c textures_bonus.c xpm_bonus.c colors_bonus.c parsing_bonus.c
EXEC_BONUS = execution_bonus.c $(addprefix rendering/, $(RENDERING_BONUS)) $(addprefix movement/, $(MOVEMENT_BONUS)) $(addprefix utils/, $(UTILS_EXEC_BONUS)) $(addprefix draw/, $(DRAW_BONUS)) $(addprefix raycasting/, $(RAYCASTING_BONUS))
BONUS = main_bonus.c $(addprefix parsing/, $(PARSING_BONUS)) $(addprefix execution/, $(EXEC_BONUS)) $(addprefix utils/, $(UTILS_BONUS))


# SOURCES
MANDATORY_SRCS = $(addprefix Mandatory/, $(MANDATORY))
BONUS_SRCS = $(addprefix Bonus/, $(BONUS))

# OBJECTS
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
GNL_OBJS = $(GNL:.c=.o)
 
all: $(NAME)

$(NAME): prepare_libft $(MANDATORY_OBJS) $(GNL_OBJS)
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(GNL_OBJS) $(LIBFT) $(MLX) -o cub3D
	@echo "cub3D is ready"

bonus: prepare_libft $(BONUS_OBJS) $(GNL_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) $(LIBFT) $(MLX) -o cub3D_bonus
	@echo "cub3D_bonus is ready"

prepare_libft:
	@cd libs/libft && make
	@echo "libft is ready"

%.o: %.c $(M_HEADERS)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) -Imlx -c -c $< -o $@

%_bonus.o: %_bonus.c $(B_HEADERS)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) -Imlx -c -c $< -o $@

clean:
	@cd libs/libft && make clean
	@rm -f $(MANDATORY_OBJS) $(GNL_OBJS) $(BONUS_OBJS)
	@echo "cub3D is clean"

fclean: clean
	@rm -f $(NAME) cub3D_bonus
	@cd libs/libft && make fclean
	@echo "cub3D is fully clean"

re: fclean all

.PHONY: prepare_libft clean fclean