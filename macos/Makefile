NAME = fdf

SRCS_DIR = ../srcs/
SRCS_FILES =	main.c \
				make_data.c \
				read_map.c \
				plotting.c \
				rotation.c \
				key_hooks.c \
				projections.c \
				exits.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ = ${SRCS:.c=.o}

HEADERS = $(SRCS_DIR)cub.h

# ========== libraries ==========
LIB_DIR = ../libs

MLX_DIR = $(LIB_DIR)/minilibx_macos
# MLX_DIR = $(LIB_DIR)/minilibx_mms_20191025_beta
MLX_LIB	=	mlx

LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_A = $(LIBFT_DIR)/libft.a


ALL_LIBS = $(LIBFT_A)

# ========== compilation ==========
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAFS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
INCLUDES_LOCAL = -I$(SRCS_DIR) -I$(LIBFT_DIR)
# ========== rules ==========
all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) $(INCLUDES_LOCAL) $(ALL_LIBS) $(HEADERS) $(MLX_FLAFS) -o $(NAME)

# %.o: %.c $(HEADERS) makelibs
# 	$(CC) $(CFLAGS) $(INCLUDES_LOCAL) -I/usr/include -Imlx_linux -c $< -o $@ 

$(NAME): makelibs $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)	-L$(LIBFT_DIR)			-lft \
							-L$(MLX_DIR) 			-l$(MLX_LIB) \
							-L/usr/lib -lm -lz -framework OpenGL -framework AppKit \
							-o $(NAME)

%.o: %.c $(HEADERS) makelibs
	$(CC) $(CFLAGS) -O3 -c $< -o $@

makelibs:
	make -C $(MLX_DIR)
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