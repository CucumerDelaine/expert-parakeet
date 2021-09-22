NAME = pipex
LIST = ft_putstr_fd.c ft_split.c ft_split2.c ft_strjoin.c ft_strlen.c ft_strncmp.c pipex.c
OBJ = $(patsubst %.c,%.o,$(LIST))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Werror -Wextra -Imlx
CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
	
%.o : %.cmkae
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

bonus:

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: bonus clean fclean all re
