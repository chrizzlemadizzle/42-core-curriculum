# source and object files
SRC = $(addsuffix .c, ft_printf)
OBJS = $(SRC:.c=.o)
UTILS_SRC = $(addprefix utils/, $(addsuffix .c, ft_strchr ft_putchar ft_putstr ft_strlen ft_putnbr ft_putnbr_base ft_putptr))
UTILS_OBJS = $(UTILS_SRC:.c=.o)
OBJS_ALL = $(OBJS) $(UTILS_OBJS)

# name of library
NAME = libftprintf.a

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

$(NAME): $(OBJS_ALL)
	ar rcs $(NAME) $(OBJS_ALL)

%.o: %.c
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.Phony: all re clean fclean
