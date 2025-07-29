NAME = minishell

CC = cc

SRC =  ft_parce.c     ft_puterror.c    ft_word.c           libft/ft_isalpha.c  libft/ft_putstr_fd.c  libft/ft_strstr.c     list/ft_list_add_back.c  minishell.c \
			 ft_print_it.c  ft_spliting.c  ft_tokenisation.c  libft/ft_isalnum.c  libft/ft_isdigit.c  libft/ft_strlen.c     list/ft_clear_list.c  list/ft_newlist.c        ft_operator.c\
			 libft/ft_strdup.c   libft/ft_itoa.c ft_heredoc_fork.c ft_signal.c  ft_status.c       libft/ft_lengh_of_table.c  gnl/get_next_line.c gnl/get_next_line_utils.c     ft_heredoc.c    libft/ft_strcmp.c libft/ft_strjoin.c   libft/ft_freetable.c\
			 list/ft_memset.c libft/ft_strchr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

MALLOC = malloc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -lreadline -I $(MALLOC) $(OBJ) -o $(NAME)

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

.PHONY : clean all re fclean
