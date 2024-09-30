# source and object files
SRC = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_strlcpy ft_strlcat ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd)
OBJS = $(SRC:.c=.o)
BONUS_SRC = $(addsuffix .c, ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
OBJS_ALL = $(OBJS) $(BONUS_OBJS)

# name of library
NAME = libft.a

# compiler
CC = cc
CCFLAGS = -Wall -Wextra -Werror

# where to look for header files
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)

# rules:
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS_ALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_ALL)
	ar rcs $(NAME) $(OBJS_ALL)

.Phony: all re clean bonus fclean
