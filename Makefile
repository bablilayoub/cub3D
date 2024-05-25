# Created Ayoub Bablil

# NAME
NAME = cub3D

# HEADERS
HEADER = cub3D.h

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
LINKS =	-lmlx -framework OpenGL -framework AppKit

# LIBRARIES
LIBFT = ./utils/libft/libft.a
GNL = ./utils/get_next_line/get_next_line.c ./utils/get_next_line/get_next_line_utils.c

# GENERAL
MAIN = main.c

# UTILS
UTILS_HEADER = ./utils/utils.h
UTILS = errors.c free.c tools.c

# PARSING
PARSING_HEADER = ./parsing/parsing.h
PARSING = parsing.c checking.c coverting.c map.c more_checking.c print.c reading.c textures.c

# SOURCES
PARSING_SRCS = $(addprefix parsing/, $(PARSING))
UTILS_SRCS =  $(addprefix utils/, $(UTILS))

# OBJECTS
PARSING_OBJS = $(PARSING_SRCS:.c=.o)
MAIN_OBJS = $(MAIN:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)
GNL_OBJS = $(GNL:.c=.o)

# HEADER
HEADERS = $(HEADER) $(PARSING_HEADER) $(UTILS_HEADER)
 
$(NAME): prepare_libft $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS)
	@cc $(CFLAGS) $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS) $(LIBFT) $(LINKS) -o $(NAME)
	@echo "cub3D is ready"

prepare_libft:
	@cd ./utils/libft && make
	@echo "cub3D is ready"

%.o: %.c $(HEADER)
	@echo "compiling $<"
	@cc $(CFLAGS) -Imlx -c -c $< -o $@

all: $(NAME)

clean:
	@cd ./utils/libft && make clean
	@rm -f $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(GNL_OBJS)
	@echo "cub3D is clean"

fclean: clean
	@rm -f $(NAME)
	@cd ./utils/libft && make fclean
	@echo "cub3D is fully clean"

re: fclean all

# PHONY
.PHONY: prepare_libft clean fclean 