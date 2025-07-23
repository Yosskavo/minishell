/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:08:29 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/23 06:16:06 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *ft_check_expention(char *str, char *remain, int *i)
{
	char *dest;

	if (!remain)
	{
		remain = ft_strdup("");
		if (!remain)
			return (perror("minishell"), NULL);
	}
	
}

static void ft_try_expend(t_parce *parce)
{
	int	i;
	char *str;

	i = 0;
	str = NULL;
	while (parce->str[i])
	{
		if (parce->str[i] == '\'')
		{
			i++;
			while (parce->str[i++] != '\'');
		}
		if (parce->str[i] == '$')
			str = ft_check_expention(parce->str, str, &i);
		else
			i++;
	}
}

int	ft_expention(t_shell *mini)
{
	t_parce *parce;
	int			i;

	parce = mini->start;
	while (pacre)
	{
		if (parce->token == WORD)
		{
			i = 0;
			while (parce->str[i] && parce->str[i] != '$')
			{
				if (parce->str[i] == '\'')
				{
					i++;
					while (parce->str[i++] != '\'');
				}
				else
					i++;
			}
			if (parce->str[i] == '$')
				ft_try_expend(parce);
		}
		parce = pcare->next;
	}
	return (0);
}

