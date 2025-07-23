/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:16:29 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/23 01:58:48 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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
	DELEMITER,
	FILENAME,
	ERROR_TOCKEN,
}					e_tocken;

typedef struct s_parce
{
	char			*str;
	e_tocken		tocken;
	int				fd_in;
	int				fd_out;
	struct s_parce	*next;
	struct s_parce	*previous;
	struct s_mini	*mini;
}					t_parce;

// this struct will be the main struct
// it will link with every struct we have here

typedef struct s_mini
{
	t_parce	*start;
	char	*str;
	char	**env;
}			t_mini;

t_parce				*ft_newlist(char *str);
void				*ft_list_add_back(t_parce **lst, t_parce *n);
t_parce				*ft_list_last(t_parce *lst);
void				ft_clear_list(t_parce **lst);
void				*ft_memset(void *s, int c, size_t n);

#endif
