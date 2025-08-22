/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:02:31 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/22 03:54:49 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static char	*ft_expend_status(void)
{
	char	*dest;

	dest = ft_itoa(ft_status(-1));
	if (!dest)
		ft_malloc_faild();
	return (dest);
}

static int	ft_check_is_valid(char *str, int *i)
{
	if (ft_valid_expention(str[*i]) != 2)
		return (-1);
	while (str[*i] && ft_valid_expention(str[*i]))
		(*i)++;
	return (1);
}

static char	*ft_expend_search(char *str, int *i, int *flag)
{
	int		j;
	char	*dest;

	if (str[*i + 1] == '?')
		return ((*i)++, *flag = 1, ft_expend_status());
	j = (*i);
	(*i)++;
	if (ft_check_is_valid(str, i) < 0)
	{
		dest = ft_strndup(str + j, (*i) - j);
		if (!dest)
			ft_malloc_faild();
		*flag = 0;
		return (dest);
	}
	dest = ft_search_expend(str + j + 1, (*i) - j - 1);
	*flag = 1;
	if (!dest)
		return (NULL);
	dest = ft_strdup(dest);
	if (!dest)
		ft_malloc_faild();
	return (dest);
}

static void	ft_help(char *dest, t_parce *parce, int flag)
{
	char	*dst;

	if (!(parce->exp->exp))
	{
		parce->exp->exp = ft_strdup(dest);
		if (!(parce->exp->exp))
			ft_malloc_faild();
	}
	else
	{
		dst = ft_strjoin(parce->exp->exp, dest);
		free(parce->exp->exp);
		parce->exp->exp = dst;

	}
	if (flag == 0)
		ft_fullmap_expand(parce->exp, OLD_CHAR, ft_strlen(dest));
	else
		ft_fullmap_expand(parce->exp, EXP_CHAR, ft_strlen(dest));
	free(dest);
}

void	ft_expend_it(t_parce *parce)
{
	int		i;
	int		flag;
	char	*dest;

	i = 0;
	while (parce->str[i])
	{
		if (parce->str[i] == '$')
			dest = ft_expend_search(parce->str, &i, &flag);
		else
		{
			dest = ft_chardup(parce->str[i++]);
			flag = 0;
		}
		if (!dest)
			continue ;
		ft_help(dest, parce, flag);
	}
	if (parce->tocken == FILENAME)
		parce->tocken = FILENAME_EXPEND;
	else
		parce->tocken = EXPEND;
}
