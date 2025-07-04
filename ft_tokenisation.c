/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:18:01 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/04 17:40:50 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

// static int ft_string_tocken(char *s)
// {
//   if ((s[0] == '<' || s[0] == '>') && s[1] == '\0')
//     return (1);
//   if (s[0] == '<' && s[1] == '<' && s[2] == '\0')
//     return (1);
//   if (s[0] == '>' && s[1] == '>' && s[2] == '\0')
//     return (1);
//   if (s[0] == '|' && s[1] == '\0')
//     return (1);
//   if (s[0] == '$')
//     return (1);
//   return (0);
// }

static void ft_operation_tocken(t_parce *parce)
{
  while (parce)
  {
    if (ft_strstr(parce->str, "<<"))
      parce->tocken = HEREDOC;
    else if (ft_strstr(parce->str, ">>"))
      parce->tocken = APPEND;
    else if (ft_strstr(parce->str, ">"))
      parce->tocken = OVERWRITE;
    else if (ft_strstr(parce->str, "<"))
      parce->tocken = REDIRACTION;
    else if (ft_strstr(parce->str, "|"))
      parce->tocken = PIPE;
    else
      parce->tocken = WORD;
    parce = parce->next;
  }
}

// static void ft_string_tocken(t_parce *parce)
// {
// 	int	i;
//
// 	i = 0;
// 	while (parce->str[i])
// 	{
// 		if (parce->str[i] == '\"' || parce->str[i] == '\'')
// 		{
// 			if (parce->str[i] == '\"')
// 				parce->tocken = DOUBLE_QOTS;
// 			else
// 				parce->tocken = SINGL_QOTS;
// 			return ;
// 		}
// 		i++;
// 	}
// }

void ft_tokenization(t_parce *parce)
{
	// t_parce *tmp;

	// while (parce)
	// {
	// 	// if (ft_operation_check(parce->str))
	//    ft_operation_tocken(parce);
	//    // else
	//    //   ft_string_tocken(parce);
	// 	parce = parce->next;
	// }
  ft_operation_tocken(parce);
  ft_split_tocken(parce);
}

