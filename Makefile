NAME = minishell

CC = cc

#SRC = minishell.c ft_env.c              ft_heredoc.c       ft_print_it.c  ft_tokenisation.c          libft/ft_isalnum.c         libft/ft_putstr_fd.c  libft/ft_strlen.c    list/ft_clear_list.c ft_expantion.c        ft_heredoc_fork.c  ft_puterror.c  ft_word.c                  libft/ft_isalpha.c         libft/ft_strchr.c     libft/ft_strncmp.c   list/ft_list_add_back.c ft_expantion_utils.c  ft_malloc_faild.c  ft_signal.c    gnl/get_next_line.c        libft/ft_isdigit.c         libft/ft_strcmp.c     libft/ft_strndup.c   list/ft_memset.c ft_expend_it.c        ft_operator.c      ft_spliting.c  gnl/get_next_line_utils.c  libft/ft_itoa.c            libft/ft_strdup.c     libft/ft_strnjoin.c  list/ft_newlist.c ft_global.c           ft_parce.c         ft_status.c    libft/ft_freetable.c       libft/ft_lengh_of_table.c  libft/ft_strjoin.c    libft/ft_strstr.c

SRC := $(wildcard */*.c) $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -lreadline -I $(MALLOC) $(OBJ) -o $(NAME)

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

.PHONY : clean all re fclean
