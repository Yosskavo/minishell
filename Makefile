NAME = minishell

CC = cc

SRC = ft_env.c              ft_spliting.c              libft/ft_strcmp.c \
	  ft_expantion.c        ft_status.c                libft/ft_strdup.c \
	  ft_expantion_utils.c  ft_tokenisation.c          libft/ft_strjoin.c \
	  ft_expend_it.c        ft_word.c                  libft/ft_strlen.c \
	  ft_expend_split_it.c  gnl/get_next_line.c        libft/ft_strncmp.c \
	  list/ft_global.c      gnl/get_next_line_utils.c  libft/ft_strndup.c \
	  ft_heredoc.c          libft/ft_freetable.c       libft/ft_strnjoin.c \
	  ft_heredoc_fork.c     libft/ft_isalnum.c         libft/ft_strstr.c \
	  ft_malloc_faild.c     libft/ft_isalpha.c         list/ft_clear_list.c \
	  ft_operator.c         libft/ft_isdigit.c         list/ft_list_add_back.c \
	  ft_parce.c            libft/ft_itoa.c            list/ft_memset.c \
	  ft_print_it.c         libft/ft_lengh_of_table.c  list/ft_newlist.c \
	  ft_puterror.c         libft/ft_putstr_fd.c       minishell.c \
	  ft_signal.c           libft/ft_strchr.c


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
