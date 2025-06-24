NAME = minishell

CC = cc

SRC = minishell.c 

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

