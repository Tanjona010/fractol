NAME	= fractol

CC		= cc

SRC		= main.c fractal_utils.c utils.c ft_atoif.c error.c event.c

CFLAGS	= -Wall -Werror -Wextra

OBJ		= $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g

$(NAME): $(OBJ)
	make -C mlx_linux
	make -C libft 
	$(CC) $(OBJ) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean	:
		make clean -C libft
		rm -f $(OBJ)

fclean	: clean
		make fclean -C libft
		rm -f $(NAME)

re		: fclean all
