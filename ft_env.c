/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:48:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/13 08:45:02 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static char	*ft_env_val(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '=')
		i++;
	return (ft_strdup(env + i + 1));
}

static char	*ft_env_var(char *env)
{
	int	size;

	size = 0;
	while (env[size] != '=')
		size++;
	return (ft_strndup(env, size));
}

t_env	*ft_envcpy(char **o_env)
{
	t_env	*env;
	t_env	*tmp;
	int		i;

	i = 0;
	env = NULL;
	while (o_env[i])
	{
		tmp = ft_lstnew_env(ft_env_var(o_env[i]), ft_env_val(o_env[i]));
		if (!tmp)
			return (ft_clear_env(&env), ft_malloc_faild(), NULL);
		ft_lstadd_back_env(&env, tmp);
		i++;
	}
	return (env);
}
