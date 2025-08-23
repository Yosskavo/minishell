/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/22 01:45:42 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_expend_everything(t_parce *parce)
{
	while (parce)
	{
		if ((parce->tocken == WORD || parce->tocken == FILENAME)
			&& ft_any_dolar_sign(parce->str))
		{
			parce->exp = malloc(sizeof(t_expend));
			if (!parce->exp)
				ft_malloc_faild();
			ft_memset(parce->exp, 0, sizeof(t_expend));
			ft_expend_it(parce);
		}
		parce = parce->next;
	}
}

static void	ft_expend_split(t_parce *parce)
{
	while (parce)
	{
		if (parce->tocken == EXPEND || parce->tocken == FILENAME_EXPEND)
			ft_expend_split_it(parce);
		parce = parce->next;
	}
}

void	ft_expention(t_mini *mini)
{
	ft_expend_everything(mini->start);
	ft_expend_split(mini->start);
	mini->start = ft_expend_link_list(mini->start);
}
