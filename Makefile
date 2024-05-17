# Created Ayoub Bablil

# NAME
NAME = cube3D

# HEADERS
HEADER = cube3D.h

CFLAGS = -Wall -Wextra -Werror -g

# LIBRARIES
LIBFT = ./utils/libft/libft.a

# GENERAL
MAIN = main.c

# UTILS
UTILS_HEADER = ./utils/utils.h
UTILS = ./utils/errors.c

# PARSING
PARSING_HEADER = ./parsing/parsing.h
PARSING = parsing.c $(addprefix validating/, $(VALIDATING))

# SOURCES
PARSING_SRCS = $(addprefix parsing/, $(PARSING))

# OBJECTS
PARSING_OBJS = $(PARSING_SRCS:.c=.o)
MAIN_OBJS = $(MAIN:.c=.o)
UTILS_OBJS = $(UTILS:.c=.o)

# HEADERS
HEADERS = $(HEADER) $(PARSING_HEADER) $(UTILS_HEADER)
 
$(NAME): prepare_libft $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS)
	@cc $(CFLAGS) $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS) $(LIBFT) -o $(NAME)
	@echo "cube3D is ready"

prepare_libft:
	@cd ./utils/libft && make
	@echo "cube3D is ready"

%.o: %.c $(HEADER)
	@echo "compiling $<"
	@cc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@cd ./utils/libft && make clean
	@rm -f $(PARSING_OBJS) $(MAIN_OBJS) $(UTILS_OBJS)
	@echo "cube3D is clean"

fclean: clean
	@rm -f $(NAME)
	@cd ./utils/libft && make fclean
	@echo "cube3D is fully clean"

re: fclean all

# PHONY
.PHONY: prepare_libft clean fclean 