/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:12:43 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/01 14:14:05 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void ft_print_it(t_parce *parce)
{
	while (parce)
	{
		printf("str : %s --- tocken : ", parce->str);
	  switch (parce->tocken) 
    {
      case PIPE :
        printf ("pipe\n");
        break ;
      case HEREDOC :
        printf("heredoc\n");
        break ;
      case OVERWRITE :
        printf("overwrite\n");
        break ;
      case DOLLAR_SIGN :
        printf("doolar sign\n");
        break ;
      case WORD :
        printf("word\n");
        break ;
      case REDIRACTION :
        printf ("rediraction\n");
        break ;
      case APPEND :
        printf ("append\n");
        break ;
	  }
    parce = parce->next;
	}
}
