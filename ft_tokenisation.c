/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:18:01 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/06 14:01:41 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static e_tocken  ft_tocken(char *str)
{
  if (str[0] == '<' && str[1] == '<' && str[2] == '\0')
    return (HEREDOC);
  if (str[0] == '>' && str[1] == '>' && str[2] == '\0')
    return (APPEND);
  if (str[0] == '>' && str[1] == '\0')
    return (OVERWRITE);
  if (str[0] == '<' && str[1] == '\0')
    return (REDIRACTION);
  if (str[0] == '|' && str[1] == '\0')
    return (PIPE);
  return (ERROR_TOCKEN);
}

void ft_tokenization(t_parce *parce)
{
  while (parce)
  {
    if (*(parce->str) == '<' || *(parce->str) == '>' || *(parce->str) == '|')
      parce->tocken = ft_tocken(parce->str);
    else
      parce->tocken = WORD;
    parce = parce->next;
  }
}

