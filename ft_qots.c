/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:44:35 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/02 23:20:55 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_expend_size_without_qots(t_parce *parce)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (parce->str[i])
	{
		if (parce->str[i] != '\'' && parce->str[i] != '\"'
			&& parce->str[i] != '0')
			size++;
		i++;
	}
	return (size);
}

static int	ft_size_without_qots(t_parce *parce)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (parce->str[i])
	{
		if (parce->str[i] != '\'' && parce->str[i] != '\"')
			size++;
		i++;
	}
	return (size);
}

static void	ft_normal_delete_qots(t_parce *parce)
{
	int		size;
	int		i;
	int		j;
	char	*dest;

	size = ft_size_without_qots(parce);
	dest = malloc(size + 1);
	if (!dest)
		ft_malloc_faild();
	i = 0;
	j = 0;
	while (size > i)
	{
		if (parce->str[j] == '\"' || parce->str[j] == '\'')
			j++;
		else
		{
			dest[i] = parce->str[j];
			i++;
			j++;
		}
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
	char	*dest;

	size = ft_expend_size_without_qots(parce);
	dest = malloc(size + 1);
	if (!dest)
		ft_malloc_faild();
	i = 0;
	j = 0;
	while (size > i)
	{
		if (parce->str[j] == '0' && (parce->str[j] == '\"'
				|| parce->str[j] == '\''))
			j++;
		else
			dest[i++] = parce->str[j++];
	}
	dest[i] = '\0';
	free(parce->str);
	parce->str = dest;
}

void	ft_delete_qots(t_parce *parce)
{
	ft_is_qoted(parce);
	while (parce)
	{
		if (parce->qoted == 1 && (parce->tocken == WORD
				|| parce->tocken == DELEMITER))
			ft_normal_delete_qots(parce);
		else if (parce->qoted == 1 && (parce->tocken == FILENAME_EXPEND
				|| parce->tocken == EXPEND))
			ft_expend_delete_qots(parce);
		parce = parce->next;
	}
}
