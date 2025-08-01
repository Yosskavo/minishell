/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_split_it.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:21:31 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/01 08:09:58 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_till_space_expend(t_expend *exp, int i)
{
	int		j;
	char	c;

	j = 0;
	while (exp->exp[i + j] && (exp->exp[i + j] != ' ' && (exp->exp[i + j] < 9
				|| exp->exp[i + j] > 13)))
	{
		if ((exp->exp[i + j] == '\"' || exp->exp[i + j] == '\'') && exp->map[i
				+ j] == '0')
		{
			c = exp->exp[i + j];
			j++;
			while (!(exp->exp[i + j] == c && exp->map[i + j] == '0'))
				j++;
			j++;
		}
		else
			j++;
	}
	return (j);
}

static void	ft_expend_token(t_parce *parce)
{
	while (parce)
	{
		parce->tocken = EXPEND;
		parce = parce->next;
	}
}

static void	ft_expend_word(t_expend *exp, t_parce **parce, int *i)
{
	char	*dest;
	int		size;
	int		j;

	size = ft_till_space_expend(exp, *i);
	dest = malloc(size + 1);
	if (!dest)
		ft_malloc_faild();
	j = 0;
	while (j < size)
	{
		dest[j] = exp->exp[*i + j];
		j++;
	}
	dest[j] = '\0';
	if (!ft_list_add_back(parce, ft_newlist(dest)))
		ft_malloc_faild();
	(*i) += size;
}

void	ft_expend_split_it(t_parce *parce)
{
	int			i;
	t_expend	*exp;
	t_parce		*tmp;

	i = 0;
	tmp = NULL;
	exp = parce->exp;
	if (!exp->exp)
		return ;
	while (exp->exp[i])
	{
		while (exp->exp[i] == ' ' || (exp->exp[i] >= 9 && exp->exp[i] <= 13))
			i++;
		if (exp->exp[i])
			ft_expend_word(exp, &tmp, &i);
	}
	parce->exp->parce = tmp;
	ft_expend_token(tmp);
}
