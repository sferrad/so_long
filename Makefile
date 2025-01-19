NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
SRC_DIR = ./src

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

# Sources and Headers
SRCS = $(SRC_DIR)/so_long.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/parsing_utils.c \
       $(SRC_DIR)/parsing_utils2.c \
       $(SRC_DIR)/floodfill.c \
       $(SRC_DIR)/mouvement.c \
	   $(SRC_DIR)/mlx_utils.c \
	   $(SRC_DIR)/mlx_utils2.c 
OBJS = $(SRCS:.c=.o)
HEADERS = -I ./includes \
          -I $(LIBFT_DIR) \
          -I $(MLX_DIR)

# Additional Flags
MLX_FLAGS = -L $(MLX_DIR) -lX11 -lXext
RM = rm -f

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
PURPLE = \033[0;35m
RESET = \033[0m

# Minilibx download URL
MLX_URL = https://cdn.intra.42.fr/document/document/28246/minilibx-linux.tgz

all: $(MLX_LIB) $(LIBFT) $(NAME)
	@echo  "$(GREEN)[INFO] Compilation completed successfully.$(RESET)"
	@echo "$(PURPLE)"
	@echo " .oooooo..o   .oooooo.               ooooo          .oooooo.   ooooo      ooo   .oooooo.    "
	@echo "d8P'    \`Y8  d8P'  \`Y8b              \`888'         d8P'  \`Y8b  \`888b.     \`8'  d8P'  \`Y8b   "
	@echo "Y88bo.      888      888              888         888      888  8 \`88b.    8  888           "
	@echo " \`\"Y8888o.  888      888              888         888      888  8   \`88b.  8  888           "
	@echo "     \`\"Y88b 888      888              888         888      888  8     \`88b.8  888     ooooo "
	@echo "oo     .d8P \`88b    d88'              888       o \`88b    d88'  8       \`888  \`88.    .88'  "
	@echo "8\"\"88888P'   \`Y8bood8P'  ooooooooooo o888ooooood8  \`Y8bood8P'  o8o        \`8   \`Y8bood8P'   "
	@echo "                                                                                             "
	@echo  "$(RESET)"
	@echo "$(GREEN)[INFO] BON JEU !$(RESET)"

$(MLX_LIB):
	@echo "$(YELLOW)[INFO] Downloading and compiling minilibx...$(RESET)"
	curl -O $(MLX_URL)
	tar -xf minilibx-linux.tgz
	make --directory=$(MLX_DIR)
	rm -rf minilibx-linux.tgz

$(LIBFT):
	@echo  "$(YELLOW)[INFO] Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo  "$(YELLOW)[INFO] Linking objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) $(HEADERS) -o $(NAME)

%.o: %.c
	@echo  "$(YELLOW)[INFO] Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@echo  "$(RED)[INFO] Cleaning up object files...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	make --directory=$(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@echo  "$(RED)[INFO] Removing executable and libraries...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
