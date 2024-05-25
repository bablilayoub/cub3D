# Created Ayoub Bablil && Achraf Laalalma

# NAME
NAME = cube3D

# HEADERS
HEADER = cube3D.h

CFLAGS = -Wall -Wextra -Werror -g

# LIBRARIES
LIBFT = ./utils/libft/libft.a
GNL = ./utils/get_next_line/get_next_line.c ./utils/get_next_line/get_next_line_utils.c

#mlx
MLX = -lmlx -framework OpenGL -framework AppKit

# GENERAL
MAIN = main.c

# UTILS
UTILS_HEADER = ./utils/utils.h
UTILS = ./utils/errors.c ./utils/free.c ./utils/tools.c

# PARSING
PARSING_HEADER = ./parsing/parsing.h
PARSING = parsing.c $(addprefix validating/, $(VALIDATING))

# EXECUTION
EXEC_HEADER = execution/execution.h
RENDERING = rendering.c
MOVEMENT = movement.c
EXEC = execution.c $(addprefix rendering/, $(RENDERING)) $(addprefix movement/, $(MOVEMENT))

# SOURCES
PARSING_SRCS = $(addprefix parsing/, $(PARSING))
EXEC_SRCS = $(addprefix execution/, $(EXEC))

# OBJECTS
PARSING_OBJS = $(PARSING_SRCS:.c=.o)
EXEC_OBJS = $(EXEC_SRCS:.c=.o)
MAIN_OBJS = $(MAIN:.c=.o)
UTILS_OBJS = $(UTILS:.c=.o)
GNL_OBJS = $(GNL:.c=.o)

# HEADER
HEADERS = $(HEADER) $(PARSING_HEADER) $(UTILS_HEADER)
 
$(NAME): prepare_libft $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS)
	@cc $(CFLAGS) $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS) $(LIBFT) -o $(NAME)
	@echo "cube3D is ready"


all: $(NAME)

exec: prepare_libft $(EXEC_OBJS) $(GNL_OBJS) $(LIBFT) $(EXEC_HEADER)
	@cc $(CFLAGS) $(EXEC_OBJS) $(GNL_OBJS) $(LIBFT) $(MLX) -o exec
	@echo "execution is ready"

prepare_libft:
	@cd ./utils/libft && make
	@echo "cube3D is ready"

%.o: %.c $(HEADER) $(EXEC_HEADER)
	@echo "compiling $<"
	@cc $(CFLAGS) -c $< -o $@

clean:
	@cd ./utils/libft && make clean
	@rm -f $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS) $(EXEC_OBJS)
	@echo "cube3D is clean"

fclean: clean
	@rm -f $(NAME) exec
	@cd ./utils/libft && make fclean
	@echo "cube3D is fully clean"

re: fclean all

# PHONY
.PHONY: prepare_libft clean fclean 