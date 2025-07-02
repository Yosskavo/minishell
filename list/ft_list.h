/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:16:29 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/01 13:30:23 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdio.h>

// append = >> , rediraction = < , heredoc = << , overwrite = >

typedef enum 
{
  APPEND,
	REDIRACTION,
  OVERWRITE,
  HEREDOC,
	PIPE,
	DOLLAR_SIGN,
	WORD,
}	e_tocken;

typedef struct s_parce {

	char			*str;
	e_tocken		tocken;
	struct s_parce 	*next;
}	t_parce;

t_parce *ft_newlist(char *str);
void *ft_list_add_back(t_parce **lst, t_parce *n);
t_parce *ft_list_last(t_parce *lst);
void ft_clear_list(t_parce **lst);

#endif
