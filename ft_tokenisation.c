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
      if (parce->next && parce->next->tocken == WORD)
        parce->next->tocken = FILENAME;
      else
        return (parce);
    }
    else if (parce->tocken == PIPE && !(parce->next))
      return (parce);
    else if (parce->tocken == HEREDOC)
    {
      if (parce->next && parce->tocken)
    }
  }
}

static  ft_operation_tocken(t_parce *parce)
{
  while (parce)
  {
    if (*(parce->str) == '<' || *(parce->str) == '>' || *(parce->str) == '|')
      parce->tocken = ft_tocken(parce->str);
    else
      parce->tocken = WORD;
    if (parce->tocken == ERROR_TOCKEN)
        return (parce);
    parce = parce->next;
  }
  return (NULL);
}

void ft_tokenization(t_parce *parce)
{
  t_parce *tmp;

  tmp = ft_operation_tocken(parce);
  if (tmp)
    return (ft_puterror(tmp));
  tmp = ft_check_tocken(parce);
  if (tmp)
    return (ft_puterror(tmp));
}

