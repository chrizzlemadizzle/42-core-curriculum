NAME = push_swap
BONUS = checker

SRCS = stack_utils_1.c stack_utils_2.c utils.c checks.c sort.c stack_operations_1.c stack_operations_2.c stack_operations_3.c operations_do.c costs_1.c costs_2.c costs_3.c
MAIN_SRCS = main.c
BONUS_SRCS = checker.c
OBJS = $(SRCS:.c=.o)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror -I. -g
CPPFLAGS =

all: $(NAME)

$(NAME): libft/libft.a $(OBJS) $(MAIN_OBJS)
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(OBJS) $(MAIN_OBJS) -o $(NAME) libft/libft.a

bonus: $(BONUS)

$(BONUS): libft/libft.a $(OBJS) $(BONUS_OBJS)
	$(CC) $(CCFLAGS) $(CPPFLAGS) $(OBJS) $(BONUS_OBJS) -o $(BONUS) libft/libft.a

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft/

clean:
	rm -f $(OBJS) $(MAIN_OBJS) $(BONUS_OBJS)
	make -C libft/ clean

fclean:
	rm -f $(NAME) $(BONUS)
	make -C libft/ fclean

re: fclean all


