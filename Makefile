NAME = minishell

CC = cc

SRC =  ft_parce.c ft_print_it.c ft_puterror.c  ft_putstr_fd.c    ft_spliting.c  ft_strlen.c  ft_word.c  minishell.c list/ft_newlist.c list/ft_clear_list.c  list/ft_list_add_back.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME)

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

.PHONY : clean all re fclean