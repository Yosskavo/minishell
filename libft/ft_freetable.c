/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:50:16 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/07 12:53:35 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  ft_freetable(char **table)
{
  int i;

  i = 0;
  while (table[i])
  {
    free(table[i]);
    table[i] = NULL;
    i++;
  }
  free(table);
}

