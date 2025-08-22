NAME = minishell
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude 

SRC = builtin/ft_built_in.c          execute/ft_wait.c               heredoc/ft_expend_heredoc.c  libft/ft_putstr_fd.c  libft/ft_strnjoin.c          list/ft_memset.c         utils/ft_envcpy.c \
	  builtin/ft_pwd.c               expanding/ft_any_dollar_sign.c  heredoc/ft_heredoc.c         libft/ft_split.c      libft/ft_strstr.c            list/ft_newlist.c        utils/ft_malloc_faild.c \
	  execute/ft_executable.c        expanding/ft_expantion.c        heredoc/ft_heredoc_fork.c    libft/ft_strchr.c     libft/ft_substr.c            parce/ft_operator.c      \
	  execute/ft_executable_utils.c  expanding/ft_expantion_utils.c  heredoc/ft_heredoc_read.c    libft/ft_strcjoin.c   libft/ft_valid_input.c       parce/ft_spliting.c      utils/ft_puterror.c \
	  execute/ft_execute.c           expanding/ft_expend_it.c        libft/ft_isalnum.c           libft/ft_strcmp.c     list/ft_clean_before_exec.c  parce/ft_tokenisation.c  utils/ft_signal.c \
	  execute/ft_execve.c            expanding/ft_expend_list.c      libft/ft_isalpha.c           libft/ft_strdup.c     list/ft_clear_all.c          parce/ft_transefarce.c   utils/ft_status.c \
	  execute/ft_fd.c                expanding/ft_expend_split_it.c  libft/ft_isdigit.c           libft/ft_strjoin.c    list/ft_clear_list.c         parce/ft_trans_utils.c \
	  execute/ft_fork.c              expanding/ft_qots.c             libft/ft_itoa.c              libft/ft_strlen.c     list/ft_freetable.c          parce/ft_word.c \
	  execute/ft_pipe.c              expanding/ft_qots_check.c       libft/ft_lengh_of_table.c    libft/ft_strncmp.c    utils/ft_global.c            src/ft_start.c \
	  execute/ft_redi.c              expanding/ft_qots_utils.c       libft/ft_putchar_fd.c        libft/ft_strndup.c    list/ft_list_add_back.c      src/minishell.c libft/ft_putendl_fd.c \
	  builtin/ft_echo.c              builtin/ft_env.c                builtin/ft_exit.c            libft/ft_atoi.c       builtin/ft_unset.c           list/ft_lstsize.c \
	  utils/ft_env_utils.c           builtin/ft_cd.c                 builtin/ft_export.c          builtin/ft_export_utils.c                          builtin/ft_export_print.c \
	  libft/ft_chardup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline

%.o: %.c include/mini.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: all clean fclean re
