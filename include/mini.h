/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 01:11:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/22 23:13:08 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

// headers needed in project

# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

// headers of readline

# include <readline/history.h>
# include <readline/readline.h>

// error flags for execve

# ifndef PACK_ACCESS
#  define ERROR_N ": No such file or directory\n"
#  define ERROR_F ": command not found\n"
#  define ERROR_D ": Is a directory\n"
#  define ERROR_X ": Permission denied\n"
#  define EMPTY_STR_ERROR "\'\': command not found\n"
# endif

// some exit status for execve

# ifndef STATUS_EX
#  define STATUS_X 126
#  define STATUS_F 127
#  define STATUS_D 128
#  define STATUS_N 129
# endif

// the limits in string form

# define MAX_EXIT "9223372036854775807"
# define MIN_EXIT "-9223372036854775808"

// error pack need by parcing or executing

# ifndef PACK_ERROR
#  define SIGQUIT_ERROR "Quit (core dumped)\n"
#  define HEREDOC_ERROR "minishell : warning: non delemater : "
#  define CDTMA_ERROR "minishell : cd : too many arguments\n"
#  define TOCKEN_ERROR "minishell : syntax error near unexpacted tocken "
#  define OPPERATION_ERROR "minishell : syntax error unexpacted opperation "
#  define CD_HOME_ERROR "minishell : cd : no HOME set\n"
#  define NAR_ERROR " : numeric argument required\n"
#  define TMA_ERROR "minishell : exit : too many arguments\n"
#  define MALLOC_FAILD "minishell : malloc faild\n"
#  define SQOT_ERROR "minishell : string isn't close by \'\n"
#  define DQOT_ERROR "minishell : string isn't close by \"\n"
#  define AMBIGUOUS_ERROR "minishell : ambiguous rediraction error \n"
#  define EXPORT_ERROR ": not a valid identifier\n"
# endif

// for the maping expantion

# ifndef FLAGS
#  define OLD_CHAR "0"
#  define EXP_CHAR "1"
# endif

// just some constant str

# define DECLEAR "declare -x "

// i want this as a checker for a tocken insted of do it manual
// and maybee i will need it in somewhere else

# ifndef OPPERATORS_SPECIAL
#  define S_TY_DOLLAR_SIGN "$"
#  define S_OVER_WRITE ">"
#  define S_APPEND ">>"
#  define S_HERE_DOC "<<"
#  define S_RE_DIRACTION "<"
#  define S_PIPE "|"
# endif

// append = >> , rediraction = < , heredoc = << , overwrite = >

typedef enum e_tocken
{
	APPEND,
	REDIRACTION,
	OVERWRITE,
	HEREDOC,
	PIPE,
	WORD,
	DELEMITER,
	FILENAME,
	EXPEND,
	FILENAME_EXPEND,
	ERROR_TOCKEN,
	AMBIGUOUS,
	BUILT_IN
}					t_tocken;

// this enum is for flaging if the command is a built in and witch one
// and if not built in should be command

typedef enum e_tcmd
{
	COMMAND,
	ECHO,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	CD,
	EXIT,
	ERROR
}					t_tcmd;

// this is the struct for the command
// we have two important elements error and path
// path : is the path to command interd it will be use oin
//  execve as first paramter
// error : is the error will be printed if the
//  command missing something if it is NULL
// so thats mean they are nothing wrong and ready to be executed

typedef struct s_cmd
{
	int				error;
	char			*path;
}					t_cmd;

// this struct for execution

typedef struct s_exec
{
	char			**args;
	t_cmd			*cmd;
	int				child;
	t_tcmd			tocken;
	struct s_parce	*redi;
	struct s_exec	*next;
}					t_exec;

// this will be a linked list full of the env

typedef struct s_env
{
	char			*variable;
	char			*value;
	struct s_env	*previous;
	struct s_env	*next;
}					t_env;

// this struct for exepention

typedef struct s_expend
{
	char			*exp;
	char			*map;
	struct s_parce	*parce;
}					t_expend;

// this is a struct parced by the input

typedef struct s_parce
{
	char			*str;
	char			*map;
	t_tocken		tocken;
	int				qoted;
	int				fd_in;
	int				fd_out;
	struct s_parce	*next;
	struct s_parce	*previous;
	struct s_expend	*exp;
}					t_parce;

// this struct will be the main struct
// it will link with every struct we have here

typedef struct s_mini
{
	char			*str;
	int				old_fd;
	int				fd[2];
	t_parce			*start;
	t_env			*env;
	t_exec			*execute;
}					t_mini;

// if a return of function is
// -1 or NULL thats mean error and should puterror print the error
// happend by using a flag gaven, atherwise
// perror print alot of error base on her data base on errno

// this is the function that start parcing and exicuting

int					ft_start(void);

// transfare the t_parce to t_exec

t_exec				*ft_transefarce(t_parce *parce);
int					ft_many_tocken(t_parce *parce, t_tocken tocken);
int					ft_many_tocken_between_tocken(t_parce *parce,
						t_tocken tocken, t_tocken delimeter);

// function that handle the path of command

void				ft_execute_creat_path(t_exec *execute);
void				ft_execute_check_path(t_exec *execute);
int					ft_excute_command_status(t_exec *execute, char *path);
void				ft_executable(void);

// this is an env function to copy or chnage something in env
// and the second copy linked list env to a char **

t_env				*ft_envcpy(char **o_env);
char				**ft_linked_to_envtable(void);

// status is for saving exit status, you can just
// gave -1 as an argument to return you a the last exit status
// signal containe the signals function and the handler of SIGQUIT and SIGINIT

int					ft_status(int exit_status);
void				ft_signal(void);

// this function using in parcing the input by readline

int					ft_spliting(char *str, t_parce **parce);
int					ft_qots(t_parce **parce, char *str, int *i);
int					ft_word(t_parce **parce, char *s, int *pos);
void				ft_split_operator(t_parce **parce, char *str, int *i);

// this function gave to every element a token to gave more info about
// the element

void				ft_tocken_error(t_parce *parce);
int					ft_tokenization(t_parce *parce);

// printf error i parces

void				ft_free_exec_alloc(t_exec **head);
void				ft_malloc_faild(void);
void				ft_puterror(char c);

// this function to handle heredoc

void				ft_read_herdoc(t_parce *tmp);
int					ft_heredoc(t_parce *parce);
void				*ft_fork_heredoc(t_parce *tmp);
void				ft_expend_heredoc(char *str, int *i, int fd);
void				ft_free_all_heredoc(void);

// this function are utils for expende

void				ft_expend_split_it(t_parce *parce);
void				ft_expention(t_mini *mini);
t_env				*ft_search_env_addr(char *var);
int					ft_any_dolar_sign(char *str);
void				ft_expend_it(t_parce *parce);
int					ft_valid_expention(char str);
void				ft_fullmap_expand(t_expend *exp, char *flag, int size);
int					ft_env_var_size(char *str);
char				*ft_search_expend(char *str, int size);
t_parce				*ft_expend_link_list(t_parce *mini);

// this functions is for qots that should deleted

void				ft_is_qoted(t_parce *parce);
void				ft_delete_qots(t_parce *parce);
char				*ft_qots_malloc(t_parce *parce, int flag, int *size);

// some steps before the execution

t_parce				*ft_clean_before_exec(t_parce *parce);

// this is the execution functions :

int					ft_fork(t_exec *execute);
void				ft_restor_fd(void);
int					ft_execute(t_mini *mini);
int					ft_redi(t_exec *execute);
int					ft_pipe(void *flag);
int					ft_dup(void);
void				ft_wait(t_exec *child);

// we have two decides in our last step

void				ft_execve(t_exec *execute);
void				ft_built_in(t_exec *execute);

// built in functions :

void				ft_pwd(void);
void				ft_export(t_exec *execute);
void				ft_cd(t_exec *execute);
void				ft_echo(t_exec *execute);
void				ft_env(void);
void				ft_exit(t_exec *execute);
void				ft_unset(t_exec *execute);

// ------------------- this some function from libft -----------------------

// function to check the caracters
int					ft_isalnum(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);

// valid input to check if the input is full of spaces or not

int					ft_valid_input(char *str);

// string monipulation

char				*ft_chardup(char c);
char				**ft_split(const char *str, char c);
char				*ft_strcjoin(char *so, char *ss, char c);
char				*ft_strnjoin(char const *s1, char const *s2, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(char *str);
char				*ft_strndup(char *str, int size);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *str, const char *s, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strstr(char *big_str, char *small_str);

// printing in file dicriptor

int					ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fdfd);
void				ft_putchar_fd(char c, int fd);

// calculate the lenght

size_t				ft_strlen(const char *str);
size_t				ft_lengh_of_table(char **table);

// casting

int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);

// free

void				ft_freetable(char **table);

// ------ this is the linked list functions ---------

// what is next is function of linked list ,and
// ather that i use to create or destroy a node:
// this function for clearing :

t_parce				*ft_clean_before_exec(t_parce *parce);
void				ft_clear_list(t_parce **lst);
void				ft_mini_clear_list(t_parce **lst);
void				ft_clear_env(t_env **env);
void				ft_clear_exec(t_exec **execute);
void				ft_clear(void);
void				ft_clear_all(void);

// to calculate the size of list

int					ft_listsize_env(void);

// global function

t_mini				*ft_global(t_mini *mini);
int					ft_global_var(int i);

// expend free and if allocation faild

void				ft_expend_malloc_faild(void);
void				ft_expend_free(t_parce *parce);
void				ft_export(t_exec *execute);

// creat new node

t_env				*ft_lstnew_env(char *var, char *val);
t_parce				*ft_newlist(char *str);
t_exec				*ft_newexec_lst(char **dest);

// it set all the element of struct by c

void				*ft_memset(void *s, int c, size_t n);

// return last node in linked list

t_parce				*ft_list_last(t_parce *lst);

// add back in linked list

void				*ft_list_add_back(t_parce **lst, t_parce *n);
void				ft_lstadd_back_env(t_env **head, t_env *env);
void				*ft_add_exec_list_back(t_exec **head, t_exec *new);

// duplacate the value and variable name

char				*ft_env_var(char *env);
char				*ft_env_val(char *env);

// utils of export

int					ft_var_check(char *str);
void				ft_export_error(char *str);
int					ft_export_valid_expention(char c);
void				ft_creat_or_update_env(char *var, char *val);
void				ft_export_print_it(void);

// this all the function used in minishell
#endif
