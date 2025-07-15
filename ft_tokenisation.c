/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:59:57 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 11:22:06 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static e_tocken	ft_tocken(char *str)
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

static t_parce	*ft_check_tocken(t_parce *parce)
{
	if (parce->tocken == PIPE)
		return (parce);
	while (parce)
	{
		if ((parce->tocken == OVERWRITE || parce->tocken == APPEND
				|| parce->tocken == REDIRACTION))
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
			if (parce->next && parce->next->tocken == WORD)
				parce->next->tocken = DELEMITER;
			else
				return (parce);
		}
		parce = parce->next;
	}
	return (NULL);
}

static t_parce	*ft_operation_tocken(t_parce *parce)
{
	while (parce)
	{
		if (*(parce->str) == '<' || *(parce->str) == '>'
			|| *(parce->str) == '|')
			parce->tocken = ft_tocken(parce->str);
		else
			parce->tocken = WORD;
		if (parce->tocken == ERROR_TOCKEN)
			return (parce);
		parce = parce->next;
	}
	return (NULL);
}

int	ft_tokenization(t_parce *parce)
{
	t_parce	*tmp;

	tmp = ft_operation_tocken(parce);
	if (tmp)
		return (ft_tocken_error(tmp), -1);
	tmp = ft_check_tocken(parce);
	if (tmp)
		return (ft_tocken_error(tmp), -1);
	return (0);
}
