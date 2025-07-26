/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/26 02:37:28 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_valid_expention(char *str)
{
	if (str[0] == '_' || ft_isalnum(str[0]) || str[0] == '?')
		return (1);
	return (0);
}

int	ft_expention(t_shell *mini)
{
	t_parce	*parce;

	parce = mini->start;
	while (pacre)
	{
		if (parce->token == WORD && ft_)
		{
			ft_expend_it();
		}
		parce = pcare->next;
	}
	return (0);
}
