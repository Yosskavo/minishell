/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:28:38 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/07 11:32:44 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(char *str)
{
  char *dest;
  int i;

  if (!str)
      return (NULL);
  dest = malloc(ft_strlen(str) + 1);
  if (!dest)
      return (NULL);
  i = 0;
  while (str[i])
  {
    dest[i] = str[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

