# Mlx42
MLX42_DIR := ./lib/MLX42
MLX42_DEPENDENCY := $(MLX42_DIR)/build/libmlx42.a

# Libft
LIBFT_DIR := ./lib/libft
LIBFT_DEPENDENCY := $(LIBFT_DIR)/libft.a

# Common
NAME := fractol
SRC_DIR := src
OBJ_DIR := obj
CC := cc
EXTRA_FLAGS := -flto -fomit-frame-pointer -fvisibility=hidden -march=native
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast $(EXTRA_FLAGS)
INCLUDES := -Iinclude -I$(MLX42_DIR)/include/MLX42 -I$(LIBFT_DIR)/include
LIBS := $(MLX42_DEPENDENCY) $(LIBFT_DEPENDENCY) -ldl -lglfw -pthread -lm
DEBUG_FLAGS := -g -fsanitize=address

SRC_FILES := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/fractol_data/fractol_type.c \
	$(SRC_DIR)/fractol_data/fractol_type_utils.c \
	$(SRC_DIR)/hooks/key_hook.c \
	$(SRC_DIR)/hooks/scroll_hook.c \
	$(SRC_DIR)/hooks/loop_hook.c \
	$(SRC_DIR)/utils/complex.c \
	$(SRC_DIR)/utils/complex_utils.c \
	$(SRC_DIR)/instructions.c \
	$(SRC_DIR)/fractol.c
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(MLX42_DEPENDENCY):
	@if [ ! -d $(MLX42_DIR) ]; then git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); fi
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && make -C $(MLX42_DIR)/build -j4

$(LIBFT_DEPENDENCY):
	$(MAKE) -C $(LIBFT_DIR)

debug: $(MLX42_DEPENDENCY) $(LIBFT_DEPENDENCY) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) $(DEBUG_FLAGS) -o debug

$(NAME): $(MLX42_DEPENDENCY) $(LIBFT_DEPENDENCY) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(MLX42_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f debug

re: fclean all

norm:
	norminette ./include ./src ./lib/libft

.PHONY: all clean fclean re norm
