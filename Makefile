CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c src/color.c src/fractal_element.c src/fractal_func.c src/ft_str.c src/handler.c src/put_pixel.c

OBJ = $(SRC:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
