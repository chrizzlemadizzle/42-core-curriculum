# source and object files
SRC = main.c init.c utils.c color.c user_interaction.c fractols.c
OBJS = $(SRC:.c=.o)

# name of program
NAME = fractol

# compiler
CC = cc
CCFLAGS = -Wall -Wextra -Werror -Imlx_linux -I. -g
CPPFLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(CPPFLAGS) -o $(NAME) libft/libft.a

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft/

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

# cc graphics.c -Wall -Werror -Wextra -Imlx_linux -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
