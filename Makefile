NAME := fdf
SRC :=  main.c main_utils.c ft_utils.c ft_draw_utils.c ft_draw_map.c ft_3d.c fdf_parse.c fdf_parse_utils.c ft_interpolate.c
OBJ  := $(SRC:.c=.o)

# === DEPS DIR ===

LIBFT_DIR = libft
LIBPRINTF_DIR = libprintf
LIBGNL_DIR = gnl
MINILIBX_DIR = mlx

# === DEPS NAME ===

LIBFT = $(LIBFT_DIR)/libft.a
LIBPRINTF = $(LIBPRINTF_DIR)/libftprintf.a
LIBGNL = $(LIBGNL_DIR)/libgnl.a
MINILIBX = -L$(MINILIBX_DIR) -l$(MINILIBX_DIR) -L/usr/lib -lXext -lX11 -lm -lz

# === UTILS ===

RM := rm -f

# === COMPILER ===

CC := cc
CFLAGS := -Werror -Wextra -Wall -g3
INCLUDES = -I/usr/include -I$(MINILIBX_DIR) -I includes -I $(LIBFT_DIR)/includes -I $(LIBPRINTF_DIR)/includes -I $(LIBGNL_DIR)/includes
LIBS = $(LIBPRINTF) $(LIBGNL) $(LIBFT) $(MINILIBX)

# === MAIN RULE ===

%.o : %.c
	$(CC) $(INCLUDES) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) $(MINILIBX) -o $(NAME)

# === DEPS BUILD ===

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBPRINTF):
	$(MAKE) -C $(LIBPRINTF_DIR)

$(LIBGNL):
	$(MAKE) -C $(LIBGNL_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

# === CLEANING UP ===

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBPRINTF_DIR) clean
	$(MAKE) -C $(LIBGNL_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBPRINTF)
	$(RM) $(LIBGNL)
	$(RM) $(NAME)

re:	fclean all

# === TESTS ===
