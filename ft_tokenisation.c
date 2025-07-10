/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:18:01 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/10 16:57:38 by yel-mota         ###   ########.fr       */
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

static void ft_check_tocken(t_parce *parce)
{
  while (parce)
  {
    if ((parce->tocken == OVERWRITE || parce->tocken == APPEND || parce->tocken == REDIRACTION))
    {
      parce = parce->next;
      if (parce && parce->tocken == WORD)
        parce->tocken = FILENAME;
      else
        parce->tocken = ERROR_TOCKEN;
    }
    parce = parce->next;
  }
}

static void ft_operation_tocken(t_parce *parce)
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



void ft_tokenization(t_parce *parce)
{
  ft_operation_tocken(parce);
  ft_check_tocken(parce);
}

