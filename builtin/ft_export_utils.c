/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:42:25 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/21 05:33:45 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_creat_or_update_env(char *var, char *val)
{
	t_env	*env;

	env = ft_search_env_addr(var);
	if (!env)
	{
		env = ft_lstnew_env(var, val);
		if (!env)
			return (free(var), free(env), ft_expend_malloc_faild());
		ft_lstadd_back_env(&(ft_global(NULL)->env), env);
	}
	else if (val)
	{
		free(env->value);
		env->value = val;
		free(var);
	}
}

void	ft_export_error(char *str)
{
	char	*dest;
	char	*dst;

	dest = ft_strjoin("minishel: ", str);
	if (!dest)
		ft_expend_malloc_faild();
	dst = ft_strjoin(dest, EXPORT_ERROR);
	if (!dst)
		return (free(dest), ft_expend_malloc_faild());
	free(dest);
	ft_putstr_fd(dst, 2);
	free(dst);
}

int	ft_var_check(char *str)
{
	int	i;

	i = 0;
	if (!str[0] || ft_export_valid_expention(str[0]) != 1)
		return (-1);
	while (str[i] != '=')
	{
		if (!str[i])
			return (0);
		if (!ft_export_valid_expention(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_export_valid_expention(char c)
{
	if (c == '_' || ft_isalpha(c))
		return (1);
	if (ft_isalnum(c))
		return (2);
	return (0);
}
