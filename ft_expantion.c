/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/31 13:33:13 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_expention(t_mini *mini)
{
	t_parce	*parce;

	parce = mini->start;
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
