NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[38;5;153m

SRCS = src/ft_atoi.c\
	src/ft_bzero.c\
	src/ft_calloc.c\
	src/ft_isalnum.c\
	src/ft_isalpha.c\
	src/ft_isascii.c\
	src/ft_isdigit.c\
	src/ft_isprint.c\
	src/ft_itoa.c\
	src/ft_memchr.c\
	src/ft_memcmp.c\
	src/ft_memcpy.c\
	src/ft_memmove.c\
	src/ft_memset.c\
	src/ft_strchr.c\
	src/ft_strdup.c\
	src/ft_strlcat.c\
	src/ft_strlcpy.c\
	src/ft_strlen.c\
	src/ft_strncmp.c\
	src/ft_strnstr.c\
	src/ft_strrchr.c\
	src/ft_tolower.c\
	src/ft_toupper.c\
	src/ft_putchar_fd.c\
	src/ft_putstr_fd.c\
	src/ft_putnbr_fd.c\
	src/ft_putendl_fd.c\
	src/ft_split.c\
	src/ft_substr.c\
	src/ft_strmapi.c\
	src/ft_striteri.c\
	src/ft_strtrim.c\
	src/ft_strjoin.c\
	printf/ft_printf_utils.c\
	printf/ft_printf.c\
	gnl/get_next_line.c\
	gnl/get_next_line_utils.c\
	src/ft_lstadd_back.c\
	src/ft_lstadd_front.c\
	src/ft_lstclear.c\
	src/ft_lstdelone.c\
	src/ft_lstiter.c\
	src/ft_lstlast.c\
	src/ft_lstmap.c\
	src/ft_lstnew.c\
	src/ft_lstsize.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compilating $(NAME) in progress..."
	@ar rcs $(NAME) $(OBJS) || \
	{ echo "$(RED)Compiling of $(NAME) failed, FF."; exit 1; }
	@echo "$(GREEN)Compilation of $(NAME) completed!"

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o) || \
	{ echo "$(RED)Compiling of $< failed, FF."; exit 1; }

all: $(NAME)

clean:
	@echo "$(BLUE)Cleaning $(NAME) objects in progress..."
	@$(RM) $(OBJS)
	@echo "$(GREEN)Cleaning of $(NAME) objects completed!"

fclean: clean
	@echo "$(BLUE)Cleaning $(NAME) in progress..."
	@$(RM) $(NAME)
	@echo "$(GREEN)Cleaning of $(NAME) completed!"

re: fclean all
