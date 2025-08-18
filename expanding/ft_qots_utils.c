/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qots_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:10:33 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/03 13:50:53 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_condi(char m, char c)
{
	return (m == '0' && (c == '\"' || c == '\''));
}

static int	ft_expend_size_without_qots(t_parce *parce)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	size = 0;
	while (parce->str[i])
	{
		if (ft_condi(parce->map[i], parce->str[i]))
		{
			c = parce->str[i++];
			while (!(parce->str[i] == c && parce->map[i] == '0'))
			{
				size++;
				i++;
			}
			i++;
		}
		else
		{
			size++;
			i++;
		}
	}
	return (size);
}

static int	ft_size_without_qots(t_parce *parce)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	size = 0;
	while (parce->str[i])
	{
		if (parce->str[i] == '\'' || parce->str[i] == '\"')
		{
			c = parce->str[i];
			i++;
			while (c != parce->str[i++])
				size++;
		}
		else
		{
			i++;
			size++;
		}
	}
	return (size);
}

char	*ft_qots_malloc(t_parce *parce, int flag, int *size)
{
	char	*dest;

	if (flag == 1)
		*size = ft_size_without_qots(parce);
	else
		*size = ft_expend_size_without_qots(parce);
	dest = malloc(*size + 1);
	if (!dest)
		ft_expend_malloc_faild();
	return (dest);
}
