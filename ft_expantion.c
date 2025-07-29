/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/28 13:48:07 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_any_dolar_sing(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i++] != '\'')
				;
		}
		if (str[i] == '$' && ft_valid_expention(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_expention(t_shell *mini)
{
	t_parce	*parce;

	parce = mini->start;
	while (pacre)
	{
		if (parce->token == WORD && ft_any_dolar_sign(parce->str))
		{
			ft_expend_it(parce);
		}
		parce = pcare->next;
	}
	return (0);
}
