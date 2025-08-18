/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenisation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:42:12 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 16:45:04 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static t_tocken	ft_tocken(char *str)
{
	if (!ft_strcmp(str, S_HERE_DOC))
		return (HEREDOC);
	if (!ft_strcmp(str, S_APPEND))
		return (APPEND);
	if (!ft_strcmp(str, S_OVER_WRITE))
		return (OVERWRITE);
	if (!ft_strcmp(str, S_RE_DIRACTION))
		return (REDIRACTION);
	if (!ft_strcmp(str, S_PIPE))
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
		return (ft_tocken_error(tmp), ft_status(1), -1);
	tmp = ft_check_tocken(parce);
	if (tmp)
		return (ft_tocken_error(tmp), ft_status(1), -1);
	return (0);
}
