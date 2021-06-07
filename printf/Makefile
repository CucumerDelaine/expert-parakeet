NAME = libftprintf.a
LIST = ft_printf.c print_char.c print_hex.c print_int.c print_pointer.c print_procent.c print_string.c print_ull.c itoa.c parce_flag.c disp.c type_digit.c
OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))
D_FILES = $(patsubst %.c,%.d, $(LIST) $(LIST_B))

FLAGS = -Wall -Werror -Wextra
CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
	
%.o : %.c
	gcc $(FLAGS) -c $< -o $@


bonus:

clean:
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: bonus clean fclean all re