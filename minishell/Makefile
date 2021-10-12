NAME = minishell

SRC = mainparcer.c utils.c utils_env.c utils_command.c mainlogic.c exve.c exve2.c exec3.c

SRCL = ./libft

OBJ	= $(SRC:.c=.o)

LIB		= $(SRCL)/libft.a

HEAD = minishell.h

# CFLAG	= -Wall -Wextra -Werror -g

RM		= rm -f

all: $(NAME)

%.o:	%.c $(HEAD)
	gcc $(CFLAG) -g -c $< -o $@

$(NAME):		$(OBJ) $(HEAD)
				$(MAKE) -C $(SRCL)
				gcc $(CFLAG) $(OBJ) $(LIB) -lreadline -ltermcap -g -L/Users/$(USER)/.brew/opt/readline/lib/ -I/Users/$(USER)/.brew/opt/readline/include -o $(NAME)

clean:	
		$(MAKE) clean -C $(SRCL)
		$(RM) $(OBJ)

fclean: clean
		$(MAKE) fclean -C $(SRCL)
		$(RM) $(NAME)
	
re : fclean all