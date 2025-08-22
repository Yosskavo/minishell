/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:02:31 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/22 01:47:01 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_rest_of_str(t_expend *exp, char *str)
{
	char	*dest;

	if (!(exp->exp))
		exp->exp = ft_strdup("");
	dest = ft_strjoin(exp->exp, str);
	if (!dest)
		ft_malloc_faild();
	free(exp->exp);
	exp->exp = dest;
	ft_fullmap_expand(exp, OLD_CHAR, ft_strlen(str));
}

static void	ft_expend_var(t_expend *exp, char *str, int old, int i)
{
	char	*dest;

	if (!exp->exp)
	{
		exp->exp = ft_strndup(str, i - old);
		exp->map = ft_strdup("");
		ft_fullmap_expand(exp, OLD_CHAR, i - old);
	}
	else if (i - old != 0)
	{
		dest = ft_strnjoin(exp->exp, str + old, i - old);
		if (!dest)
			ft_malloc_faild();
		free(exp->exp);
		ft_fullmap_expand(exp, OLD_CHAR, i - old);
		exp->exp = dest;
	}
}

static void	ft_expend_status(t_expend *exp, char *str, int *old, int *i)
{
	char	*dest;
	char	*dst;

	ft_expend_var(exp, str, *old, *i);
	dest = ft_itoa(ft_status(-1));
	if (!dest)
		ft_malloc_faild();
	dst = ft_strjoin(exp->exp, dest);
	if (!dst)
		return (free(dest), ft_malloc_faild());
	ft_fullmap_expand(exp, EXP_CHAR, ft_strlen(dest));
	free(dest);
	free(exp->exp);
	exp->exp = dst;
	(*old) += 2;
	(*i) += 2;
}

static void	ft_expend_continue(t_expend *exp, char *str, int *old, int *i)
{
	char	*dest;
	int		tmp;
	int		j;

	tmp = *old;
	j = *i;
	(*old) = ++(*i);
	(*i) += ft_env_var_size(str + *old);
	dest = ft_search_expend(str + *old, *i - *old);
	*old = (*i);
	if (!dest && !j)
		return ;
	ft_expend_var(exp, str, tmp, j);
	if (!dest)
		return ;
	ft_fullmap_expand(exp, EXP_CHAR, ft_strlen(dest));
	dest = ft_strjoin(exp->exp, dest);
	if (!dest)
		ft_malloc_faild();
	free(exp->exp);
	exp->exp = dest;
}

void	ft_expend_it(t_parce *parce)
{
	int	i;
	int	j;
	int	old;

	old = 0;
	i = 0;
	j = 0;
	while (parce->str[i])
	{
		j = ft_any_dolar_sign(parce->str + i) - 1;
		if (j == -1)
			break ;
		i += j;
		if (parce->str[i + 1] == '?')
			ft_expend_status(parce->exp, parce->str, &old, &i);
		else
			ft_expend_continue(parce->exp, parce->str, &old, &i);
		old = i;
	}
	if (ft_strlen(parce->str + old))
		ft_rest_of_str(parce->exp, parce->str + old);
	if (parce->tocken == FILENAME)
		parce->tocken = FILENAME_EXPEND;
	else
		parce->tocken = EXPEND;
}
