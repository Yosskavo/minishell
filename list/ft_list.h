/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:16:29 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/11 21:02:05 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

// this struct for execution

typedef struct s_exec
{
	char			**args;
	struct s_parce	*cmd;
	struct s_parce	*redi;
	struct s_exec	*next;
}					t_exec;

// this will be a linked list full of the env

typedef struct s_env
{
	char			*variable;
	char			*value;
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

// function of linked list :
//
// this function for clearing :
t_parce				*ft_clean_before_exec(t_parce *parce);
void				ft_clear_list(t_parce **lst);
void				ft_mini_clear_list(t_parce **lst);
void				ft_clear_env(t_env **env);
void				ft_clear_exec(t_exec **execute);
// global function
t_mini				*ft_global(t_mini *mini);
int					ft_global_var(int i);

// expend free and if allocation faild

void				ft_expend_malloc_faild(void);
void				ft_expend_free(t_parce *parce);

// creat new node

t_env				*ft_lstnew_env(char *var, char *val);
t_parce				*ft_newlist(char *str);
t_exec				*ft_newexec_lst(void);

// it set all the element of struct by 0

void				*ft_memset(void *s, int c, size_t n);

// return last node in linked list

t_parce				*ft_list_last(t_parce *lst);

// add back in linked list

void				*ft_list_add_back(t_parce **lst, t_parce *n);
void				ft_lstadd_back_env(t_env **head, t_env *env);
void				*ft_add_exec_list_back(t_exec **head, t_exec *new);
#endif
