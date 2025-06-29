/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 01:11:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/29 11:25:07 by yel-mota         ###   ########.fr       */
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

# ifndef PACK_ERROR
#  define SQOT_ERROR "minishell : string isn't close by \'\n"
#  define DQOT_ERROR "minishell : string isn't close by \"\n"
# endif

int ft_parcing(char *str);

int ft_spliting(char *str, t_parce *parce);


#endif