NAME = push_swap

SRC = main.c operations_1.c operations_2.c push_swap_utils_1.c push_swap_utils_2.c \
 	push_swap_utils_3.c special_cases_1.c special_cases_2.c input_checks.c ft_split.c \
	list_utils.c libft_utils.c algorithm_1.c algorithm_2.c algorithm_3.c algorithm_4.c \
	lis_first_part.c algorithm_utils.c ft_printf.c print_types1.c print_types2.c print_types3.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME)
	
clean:
	rm -rf 

fclean: clean
	rm -f $(NAME)

re: fclean all