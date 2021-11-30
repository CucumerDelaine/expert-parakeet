NAME = minishell

SRC = parcer/mainparcer.c parcer/mainparcer2.c parcer/mainparcer3.c logic/utils.c logic/utils_env.c logic/utils_command.c logic/mainlogic.c logic/exve.c logic/exve2.c logic/exec3.c logic/pipe.c logic/env.c logic/unset.c logic/exit.c logic/pipe2.c logic/pipe3.c logic/exve4.c logic/back_d_red2.c logic/utils2.c logic/cd_command.c logic/pwd_export_command.c parcer/quotes_two.c parcer/dollar.c parcer/parcer.c parcer/parcer2.c parcer/quotes_one.c parcer/redir.c logic/utils3.c logic/pwd_export_comand2.c logic/pwd_export_comand3.c parcer/parcer_utils.c

SRCL = ./libft

OBJ	= $(SRC:.c=.o)

LIB		= $(SRCL)/libft.a

HEAD = minishell.h

CFLAG	= -Wall -Wextra -Werror -g

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