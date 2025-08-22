/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:44:35 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/22 03:11:09 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_normal_delete_qots(t_parce *parce)
{
	int		size;
	int		i;
	int		j;
	char	c;
	char	*dest;

	dest = ft_qots_malloc(parce, 1, &size);
	i = 0;
	j = 0;
	while (size > i)
	{
		if (parce->str[j] == '\"' || parce->str[j] == '\'')
		{
			c = parce->str[j];
			j++;
			while (parce->str[j] != c)
				dest[i++] = parce->str[j++];
			j++;
		}
		else
			dest[i++] = parce->str[j++];
	}
	dest[i] = '\0';
	free(parce->str);
	parce->str = dest;
}

static void	ft_expend_delete_qots(t_parce *parce)
{
	int		size;
	int		i;
	int		j;
	char	c;
	char	*dest;

	dest = ft_qots_malloc(parce, 0, &size);
	i = 0;
	j = 0;
	while (size > i)
	{
		if (parce->map[j] == '0' && (parce->str[j] == '\"'
				|| parce->str[j] == '\''))
		{
			c = parce->str[j++];
			while (parce->str[j] && !(parce->str[j] == c && parce->map[j] == '0'))
				dest[i++] = parce->str[j++];
			j++;
		}
		else
			dest[i++] = parce->str[j++];
	}
	dest[i] = '\0';
	free(parce->str);+-
	parce->str = dest;
}

void	ft_delete_qots(t_parce *parce)
{
	ft_is_qoted(parce);
	while (parce)
	{
		if (parce->qoted == 1 && (parce->tocken == WORD
				|| parce->tocken == DELEMITER || parce->tocken == FILENAME))
			ft_normal_delete_qots(parce);
		else if (parce->qoted == 1 && (parce->tocken == FILENAME_EXPEND
				|| parce->tocken == EXPEND))
			ft_expend_delete_qots(parce);
		parce = parce->next;
	}
}
