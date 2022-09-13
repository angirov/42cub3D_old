NAME = cub3D

SRCS_DIR = ../srcs/
SRCS_FILES =	main.c \
				mlx_api/free_mlx.c \
				drawing.c \
				game.c \
				key_hooks.c \
				math.c \
				minimap.c \
				raycasting.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ = ${SRCS:.c=.o}

HEADERS = $(SRCS_DIR)cub.h

# ========== libraries ==========
LIB_DIR = ../libs

LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_A = $(LIBFT_DIR)/libft.a

ALL_LIBS = $(LIBFT_A)

# ========== compilation ==========
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-unused-parameter
MLX_FLAFS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MODULES = 	mlx_api \
			game
MODULES_DIRS = $(addprefix $(SRCS_DIR), $(MODULES))
MODULES_INCL = $(addprefix -I, $(MODULES_DIRS))
INCLUDES_LOCAL = -I$(SRCS_DIR) -I$(LIBFT_DIR) $(MODULES_INCL)
# ========== rules ==========
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INCLUDES_LOCAL) $(ALL_LIBS) $(HEADERS) $(MLX_FLAFS) -o $(NAME)

%.o: %.c $(HEADERS) makelibs
	$(CC) $(CFLAGS) $(INCLUDES_LOCAL) -I/usr/include -Imlx_linux -c $< -o $@ 

makelibs:
	make bonus -C $(LIBFT_DIR)

clean: cleanlibs
	rm $(OBJ)

fclean: fcleanlibs
	rm $(OBJ) $(NAME)

cleanlibs:
	make clean -C $(LIBFT_DIR)

fcleanlibs:
	make fclean -C $(LIBFT_DIR)

test:
	@echo $(OBJ)

.PHONY: all clean fclean re makelibs test