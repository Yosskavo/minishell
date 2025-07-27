/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/27 10:35:50 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*ft_rest_of_str(t_expend *exp, char *str)
{
	char	*dest;
	int		size;

	dest = ft_strjoin(exp->str, str);
	if (!dest)
		return (perror("minishell"), NULL);
	free(exp->str);
	exp->str = dest;
	size = ft_strlen(str);
	ft_fullmap_expand(exp, OLD_CHAR, size);
	return ((void *)1);
}

static void	*ft_expendjoin(t_parce *parce, char *pos, int *i)
{
	int		size;
	char	*dest;
	char	*env;

	size = pos - (parce->str + *i);
	if (!parce->exp->str)
	{
		parce->exp->str = malloc(size);
		if (!parce->exp->str)
			return (perror("minishell"), NULL);
		ft_substr(parce->exp->str, pos, size);
		ft_fullmap_expand(parce->exp, OLD_CHAR, size);
	}
	env = ft_search_for_expend(parce->str + *i);
	if (!env)
		return ;
	dest = ft_strjoin(parce->exp->str, dest);
	if (!dest)
		return (perror("minishell"));
	free(parce->exp->str);
	parce->exp->str = dest;
	ft_fullmap_expand(parce->exp, EXP_CHAR, ft_strlen(env));
}

static void	ft_expend_it(t_parce *parce)
{
	int		i;
	char	*pos;

	i = 0;
	parce->exp = malloc(sizeof(t_expend));
	if (!parce->exp)
		return (perror("minishell"));
	while (parce->str[i])
	{
		pos = ft_strchr(parce->str, '$');
		if (!pos)
		{
			if (!ft_expendjoin(parce, pos, &i))
				return ;
		}
		else
		{
			if (!ft_rest_of_str(parce->exp, pos))
				return ;
		}
		while (parce->str[i] && parce->str + i != pos)
			i++;
	}
}

static int	ft_any_dolar_sing(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && ft_valid_expention(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_expention(t_shell *mini)
{
	t_parce	*parce;

	parce = mini->start;
	while (pacre)
	{
		if (parce->token == WORD && ft_any_dolar_sign(parce->str))
		{
			ft_expend_it(parce);
		}
		parce = pcare->next;
	}
	return (0);
}
