/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:16:29 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/29 10:29:31 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef enum 
{
	PIPE,
	SINGL_QOTS,
	DOUBLE_QOTS,
	DOLLAR_SIGN,
	WORD,
	REDIRACTION,
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