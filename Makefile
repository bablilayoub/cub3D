# Created Ayoub Bablil && Achraf Laalalma

# NAME
NAME = cub3D

# HEADERS
MAIN_HEADERS = cub3D.h includes.h

# FLAGS
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

# LIBRARIES
LIBFT = utils/libft/libft.a
GNL = utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c

#mlx
MLX = -lmlx -framework OpenGL -framework AppKit

# GENERAL
MAIN = main.c

# UTILS
UTILS_HEADERS = utils/utils.h utils/get_next_line/get_next_line.h
UTILS = errors.c free.c tools.c

# PARSING
PARSING_HEADER = parsing/parsing.h
PARSING = parsing.c checking.c converting.c map.c more_checking.c print.c reading.c textures.c xpm.c

# EXECUTION
EXEC_HEADER = execution/execution.h
RENDERING = rendering.c raycasting.c wallhits.c draw.c renderwall.c
MOVEMENT = movement.c player.c
UTILS_EXEC = utils.c doors.c
EXEC = execution.c $(addprefix rendering/, $(RENDERING)) $(addprefix movement/, $(MOVEMENT)) $(addprefix utils/, $(UTILS_EXEC))

# SOURCES
PARSING_SRCS = $(addprefix parsing/, $(PARSING))
EXEC_SRCS = $(addprefix execution/, $(EXEC))
UTILS_SRCS =  $(addprefix utils/, $(UTILS))

# OBJECTS
PARSING_OBJS = $(PARSING_SRCS:.c=.o)
EXEC_OBJS = $(EXEC_SRCS:.c=.o)
MAIN_OBJS = $(MAIN:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)
GNL_OBJS = $(GNL:.c=.o)

# HEADER
HEADERS = $(MAIN_HEADERS) $(EXEC_HEADER) $(PARSING_HEADER) $(UTILS_HEADERS)
 
$(NAME): prepare_libft $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS) $(EXEC_OBJS)
	@cc $(CFLAGS) $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS) $(LIBFT) $(MLX) $(EXEC_OBJS) -o $(NAME)
	@echo "cub3D is ready"

all: $(NAME)

prepare_libft:
	@cd utils/libft && make
	@echo "libft is ready"

%.o: %.c $(HEADERS)
	@echo "compiling $<"
	@cc $(CFLAGS) -Imlx -c -c $< -o $@

clean:
	@cd utils/libft && make clean
	@rm -f $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS) $(EXEC_OBJS)
	@echo "cub3D is clean"

fclean: clean
	@rm -f $(NAME)
	@cd utils/libft && make fclean
	@echo "cub3D is fully clean"

re: fclean all

# PHONY
.PHONY: prepare_libft clean fclean 