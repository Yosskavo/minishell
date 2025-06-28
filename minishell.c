/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:02:13 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/28 11:36:59 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void ft_print_list(t_parce *parce)
{
  while (parce)
  {
    // printf("%s\n", parce->str);
    parce = parce->next;
  }
}

void print_it(t_parce *parce)
{
  ft_print_list(parce);
}

size_t ft_word(char *str)
{
  size_t i;

  i = 0;
  while ((str[i] != ' ' && !(str[i] <=  13 && str[i] >= 9)) && str[i])
    i++;
  return (i);
}

void ft_cpy_tell_spcae(char *dest, char *src)
{
  int i;

  i = 0;
  while ((src[i] != ' ' && !(src[i] <=  13 && src[i] >= 9)) && src[i])
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

int ft_parce(t_parce **lst, char *src)
{
  char *dest;
  
  dest = malloc(ft_word(src) + 1);
  if (!src)
    return (-1);
  ft_cpy_tell_spcae(dest, src);
  if (ft_edge_qot_case(dest) == -1)
    return (free(dest), dest = NULL, -1);
  ft_list_add_back(lst, ft_newlist(dest));
  return (0);
}

void  *ft_parcing_it(char *str)
{
  int i;
  t_parce *parce;

  i = 0;
  parce = NULL;
  while (str[i])
  {
    while (str[i] == ' ' ||( str[i] <=  13 && str[i] >= 9))
      i++;
    if (*(str + i) == '\'' || *(str + i) == '\"')
    {
      if (ft_qots_handle(&parce, str + i) == -1)
        return (ft_clear_list(&parce), NULL);
      i++;
      while ((str[i] != '\"' && str[i] != '\'') && str[i])
        i++;
      i++;
    }
    else
    {
      if (ft_parce(&parce, str + i) == -1)
        return (ft_clear_list(&parce), NULL);
      while ((str[i] != ' ' && !(str[i] <=  13 && str[i] >= 9)) && str[i])
        i++;
    }
  }
  print_it(parce);
}

int ft_start()
{
  char *str;

  while (1)
  {
    str = readline("mini-->>");
    if (!str)
      return (perror("minishell"), 1);
    if (*str)
      ft_parcing_it(str);
    free(str);
  }
}

int main ()
{
  // ft_putstr_fd("asdjaljd", 2);
  ft_start();
}
