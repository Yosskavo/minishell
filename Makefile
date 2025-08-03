NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_env.c              ft_expend_split_it.c  ft_parce.c     ft_status.c                libft/ft_freetable.c  libft/ft_lengh_of_table.c  libft/ft_strjoin.c   libft/ft_strstr.c        list/ft_memset.c \
	  ft_expantion.c        ft_heredoc.c          ft_print_it.c  ft_tokenisation.c          libft/ft_isalnum.c    libft/ft_putstr_fd.c       libft/ft_strlen.c    libft/ft_valid_input.c   list/ft_newlist.c \
	  ft_expantion_utils.c  ft_heredoc_fork.c     ft_puterror.c  ft_word.c                  libft/ft_isalpha.c    libft/ft_strchr.c          libft/ft_strncmp.c   list/ft_clear_list.c     minishell.c \
	  ft_expend_it.c        ft_malloc_faild.c     ft_signal.c    gnl/get_next_line.c        libft/ft_isdigit.c    libft/ft_strcmp.c          libft/ft_strndup.c   list/ft_global.c \
	  ft_expend_list.c      ft_operator.c         ft_spliting.c  gnl/get_next_line_utils.c  libft/ft_itoa.c       libft/ft_strdup.c          libft/ft_strnjoin.c  list/ft_list_add_back.c \
	  ft_qots.c             ft_qots_check.c       ft_qots_utils.c



OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) -lreadline $(OBJ) -o $(NAME)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	@rm -fv $(OBJ)

fclean : clean
	@rm -fv $(NAME)

re : fclean all

.PHONY : clean fclean re all
