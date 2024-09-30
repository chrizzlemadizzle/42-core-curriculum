# source and object files
SRC = $(addsuffix .c, ft_printf ft_strchr ft_putchar ft_putstr ft_strlen ft_putnbr ft_putnbr_base ft_putptr)
OBJS = $(SRC:.c=.o)

# name of library
NAME = libft.a

# compiler
CC = cc
CCFLAGS = -Wall -Werror -Wextra

# header files
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)

# remove function
RM = rm -f

# rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.Phony: all re clean fclean
