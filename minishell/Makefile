NAME = minishell

SRC = main.c utils.c utils_env.c libft/libft.a utils_command.c mainlogic.c exve.c exve2.c

OBJ		= $(SRC:.c=.o)

HEAD = minishell.h

CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

all: $(NAME)

$(NAME):		$(OBJ) $(HEAD)
				gcc $(CFLAG) $(OBJ) -lreadline -ltermcap -g -L/Users/$(USER)/.brew/opt/readline/lib/ -I/Users/$(USER)/.brew/opt/readline/include -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
	
re : fclean all