/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 01:11:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/05 13:38:35 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "list/ft_list.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
// # include <stdio.h>
# include <sys/wait.h>
// # include <stdlib.h>
// # include <fcntl.h>
// # include <unistd.h>

# ifndef PACK_ERROR
#  define HEREDOC_ERROR "minishell : warning: non delemater\n"
#  define TOCKEN_ERROR "minishell : syntax error near unexpacted tocken "
#  define OPPERATION_ERROR "minishell : syntax error unexpacted opperation "
#  define SQOT_ERROR "minishell : string isn't close by \'\n"
#  define DQOT_ERROR "minishell : string isn't close by \"\n"
# endif

# ifndef FLAGS
#  define OLD_CHAR "0"
#  define EXP_CHAR "1"
# endif

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

// if a return of function is
// -1 or NULL thats mean error and should puterror print the error
// happend by using a flag gaven atherwise
// perror print alot of error base on her data base

// this is an env function to copy or chnage something in env

t_env	*ft_envcpy(char **o_env);

// status is for saving exit status, you can just
// gave -1 as an argument to return you a the last exit status
// signal containe the signals function and the handler of SIGQUIT and SIGINIT

int		ft_status(int exit_status);
void	ft_signal(void);
void	ft_free_all_heredoc(void);
// this function using in parcing the input by readline

int		ft_spliting(char *str, t_parce **parce);
int		ft_parcing(t_mini *mini);
int		ft_qots(t_parce **parce, char *str, int *i);
int		ft_word(t_parce **parce, char *s, int *pos);
void	ft_split_operator(t_parce **parce, char *str, int *i);

// this function gave to every element a token to gave more info about
// the element

void	ft_tocken_error(t_parce *parce);
int		ft_tokenization(t_parce *parce);

// printf error i parces

void	ft_malloc_faild(void);
void	ft_puterror(int flag);
void	ft_print_it(t_mini *parce);
void	ft_print_it_2(t_mini *parce);

// this function to handle heredoc

void	ft_read_herdoc(t_parce *tmp);
int		ft_heredoc(t_parce *parce);
void	*ft_fork_heredoc(t_parce *tmp);
void	ft_expend_heredoc(char *str, int *i, int fd);

// this function are utils for expende

void	ft_expend_split_it(t_parce *parce);
void	ft_expention(t_mini *mini);
int		ft_any_dolar_sign(char *str);
void	ft_expend_it(t_parce *parce);
int		ft_valid_expention(char str);
void	ft_fullmap_expand(t_expend *exp, char *flag, int size);
int		ft_env_var_size(char *str);
char	*ft_search_expend(char *str, int size);
t_parce	*ft_expend_link_list(t_parce *mini);

// this functions is for qots that should deleted

void	ft_is_qoted(t_parce *parce);
void	ft_delete_qots(t_parce *parce);
char	*ft_qots_malloc(t_parce *parce, int flag, int *size);

// some steps before the execution

t_parce	*ft_clean_before_exec(t_parce *parce);

// this all the function used in minishell

#endif
