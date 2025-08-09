/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:10:46 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/03 17:29:14 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_search_expend(char *str, int size)
{
	t_env	*env;

	env = ft_global(NULL)->env;
	while (env)
	{
		if (!ft_strncmp(str, env->variable, size)
			&& size == (int)ft_strlen(env->variable))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int	ft_valid_expention(char c)
{
	if (c == '_' || ft_isalpha(c) || c == '?')
		return (2);
	if (c == '_' || ft_isalnum(c) || c == '?')
		return (1);
	return (0);
}

void	ft_fullmap_expand(t_expend *exp, char *flag, int size)
{
	int		i;
	char	*dest;

	i = 0;
	while (i < size)
	{
		dest = ft_strjoin(exp->map, flag);
		if (!dest)
			ft_malloc_faild();
		free(exp->map);
		exp->map = dest;
		i++;
	}
}

int	ft_env_var_size(char *str)
{
	int	i;

	i = 0;
	while (ft_valid_expention(str[i]))
		i++;
	return (i);
}

int	ft_any_dolar_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i++] != '\'')
				;
		}
		if (!str[i])
			break ;
		if (str[i] == '$' && str[i + 1] == '$')
			i += 2;
		if (str[i] == '$' && ft_valid_expention(str[i + 1]) == 2)
			return (i + 1);
		i++;
	}
	return (0);
}
