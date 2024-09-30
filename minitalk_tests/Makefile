#sources and objects
SRC_S = server.c
SRC_C = client.c
OBJS_S = $(patsubst %.c, %.o, $(SRC_S))
OBJS_C = $(patsubst %.c, %.o, $(SRC_C))

#name of executables
NAME_S = server
NAME_C = client

#compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS =

#rules

all: $(NAME_S) $(NAME_C)

$(NAME_S): libft/libft.a $(OBJS_S)
	$(CC) $(CFLAGS) -o $@ $(OBJS_S) libft/libft.a

$(NAME_C): libft/libft.a $(OBJS_C)
	$(CC) $(CFLAGS) -o $@ $(OBJS_C) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft/

clean:
	rm -f $(OBJS_S) $(OBJS_C)
	make -C libft/ clean

fclean:
	rm -f $(NAME_S) $(NAME_C)
	make -C libft/ fclean

re: fclean all
