/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:12:43 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/06 13:18:55 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void ft_print_it(t_parce *parce)
{
	while (parce)
	{
    if (*(parce->str) == '\0')
      printf("str : empty string \n"); // if (parce->tocken == WORD)
    else
      printf("str : %s --- tocken :", parce->str);
    if (parce->tocken == WORD)
      printf ("word \n");
    else if (parce->tocken == PIPE)
      printf ("pipe \n");
    else if (parce->tocken == APPEND)
      printf ("append \n");
    else if (parce->tocken == HEREDOC)
      printf ("heredoc \n");
    else if (parce->tocken == REDIRACTION)
      printf ("rediraction \n");
    else if (parce->tocken == OVERWRITE)
      printf ("overwrite \n");
    else if (parce->tocken == ERROR_TOCKEN)
      printf ("error\n");
    parce = parce->next;
	}
}
