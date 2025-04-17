NAME = minishell

CC = cc

SRC = minishell.c 

OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@em -fv $(NAME)

re : fclean all

.PHONY : clean all re fclean
