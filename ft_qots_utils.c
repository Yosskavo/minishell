/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qots_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:10:37 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/02 22:12:20 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_expend_check_qots(t_parce *parce)
{
	int	i;

	i = 0;
	while (parce->str[i])
	{
		if (parce->str[i] == '0' && (parce->str[i] == '\"'
				|| parce->str[i] == '\''))
		{
			parce->qoted = 1;
			break ;
		}
		i++;
	}
}

static void	ft_check_word_qots(t_parce *parce)
{
	int	i;

	i = 0;
	while (parce->str[i])
	{
		if (parce->str[i] == '\"' || parce->str[i] == '\'')
		{
			parce->qoted = 1;
			break ;
		}
		i++;
	}
}

void	ft_is_qoted(t_parce *parce)
{
	int	i;

	while (parce)
	{
		i = 0;
		if (parce->tocken == FILENAME_EXPEND || parce->tocken == EXPEND)
			ft_expend_check_qots(parce);
		if (parce->tocken == WORD || parce->tocken == DELEMITER)
			ft_check_word_qots(parce);
		parce = parce->next;
	}
}
