NAME = push_swap
LIST = atoi.c back_to_stack_a.c checker.c command_stek_1.c command_stek_2.c command_stek_3.c cor_stek2.c five_and_less_b.c found1.c found2.c ft_split.c ft_strlcpy.c ft_strlen.c func_2.c func.c lst_operation.c push_swap.c step_1_2.c step_3456.c zamena.c
OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Werror -Wextra
CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $?
	
%.o : %.cmkae
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

bonus:

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: bonus clean fclean all re
