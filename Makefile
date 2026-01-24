NAME := fdf
SRC :=  main.c
OBJ  := $(SRC:.c=.o)

# === DEPS DIR ===

LIBFT_DIR = libft
LIBPRINTF_DIR = libprintf
LIBGNL_DIR = gnl

# === DEPS NAME ===

LIBFT = $(LIBFT_DIR)/libft.a
LIBPRINTF = $(LIBPRINTF_DIR)/libftprintf.a
LIBGNL = $(LIBGNL_DIR)/libgnl.a
MINILIBX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# === UTILS ===

RM := rm -f

# === COMPILER ===

CC := cc
CFLAGS := -Werror -Wextra -Wall -g3
INCLUDES = -I/usr/include -Imlx_linux -I includes -I $(LIBFT_DIR)/includes -I $(LIBPRINTF_DIR)/includes -I $(LIBGNL_DIR)/includes
LIBS = $(MINILIBX)$(LIBPRINTF) $(LIBFT) $(LIBGNL)

# === MAIN RULE ===

%.o : %.c
	$(CC) $(INCLUDES) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)

# === DEPS BUILD ===

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBPRINTF):
	$(MAKE) -C $(LIBPRINTF_DIR)

$(LIBGNL):
	$(MAKE) -C $(LIBGNL_DIR)

# === CLEANING UP ===

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBPRINTF_DIR) clean
	make -C $(LIBGNL_DIR) clean
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBPRINTF)
	$(RM) $(LIBGNL)
	$(RM) $(NAME)

re:	fclean all

# === TESTS ===
