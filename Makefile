NAME = minishell

CC = cc

SRC =  ft_parce.c     ft_puterror.c  ft_split_tocken.c  ft_word.c           libft/ft_isalpha.c  libft/ft_putstr_fd.c  libft/ft_strstr.c     list/ft_list_add_back.c  minishell.c \
			 ft_print_it.c  ft_spliting.c  ft_tokenisation.c  libft/ft_isalnum.c  libft/ft_isdigit.c  libft/ft_strlen.c     list/ft_clear_list.c  list/ft_newlist.c        ft_operator.c

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
