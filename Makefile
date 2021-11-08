NAME = libftprintf.a

c_flags = -Wall -Werror -Wextra -c

ft_printf_functions = shared_write_functs\
					  write_base_int\
					  apply_flags\
					  write_arg

libft_functions	= isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy memmove strlcpy strlcat\
				  toupper tolower strchr strrchr strncmp memchr memcmp strnstr atoi calloc strdup\
				  substr strjoin strtrim split itoa strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd\
				  lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap


LIBFT_FUNCTIONS = $(addprefix "ft_", $(libft_functions))

all: $(NAME) clean

$(NAME):
	gcc $(c_flags) $(addsuffix ".c", $(addprefix "libft/", $(LIBFT_FUNCTIONS)) $(addprefix "functions/", $(ft_printf_functions))) ft_printf.c
	ar -crs $(NAME) $(addsuffix ".o", $(LIBFT_FUNCTIONS) $(ft_printf_functions)) ft_printf.o

bonus: all

clean:
	rm -f $(addsuffix ".o", $(LIBFT_FUNCTIONS) $(ft_printf_functions)) ft_printf.o

fclean: clean
	rm -f $(NAME)

re: fclean all clean

test: re
	gcc $(NAME) testmain.c
	./a.out
	rm -rf a.out

norm: re clean
	norminette $(addsuffix ".c", $(addprefix "functions/", $(ft_printf_functions))) functions/ft_printf_functs.h ft_printf.c ft_printf.h

.PHONY: all clean fclean re bonus test norm
