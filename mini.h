/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 01:11:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/06 13:21:24 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "list/ft_list.h"
# include "libft/libft.h"

# ifndef PACK_ERROR
#  define SQOT_ERROR "minishell : string isn't close by \'\n"
#  define DQOT_ERROR "minishell : string isn't close by \"\n"
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

// if a return of function is -1 or NULL thats mean error and should puterror printf the error
// happend by using a flag gaven atherwise perror print alot of error base on her data base

int ft_parcing(char *str);
int ft_qots(t_parce **parce, char *str, int *i);

int ft_spliting(char *str, t_parce **parce);
int ft_word(t_parce **parce, char *s, int *pos);
void ft_tokenization(t_parce *parce);
int ft_split_operator(t_parce **parce, char *str, int *i);
void ft_puterror(int flag);

void ft_print_it(t_parce *parce);

#endif
