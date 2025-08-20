/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:48:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/20 02:10:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_env	*ft_search_env_addr(char *var)
{
	t_env	*env;

	env = ft_global(NULL)->env;
	while (env && ft_strcmp(env->variable, var))
		env = env->next;
	return (env);
}

char	**ft_linked_to_envtable(void)
{
	t_env	*env;
	char	**dest;
	int		i;

	env = ft_global(NULL)->env;
	dest = malloc(sizeof(char *) * (ft_listsize_env() + 1));
	if (!dest)
		ft_expend_malloc_faild();
	i = 0;
	while (env)
	{
		dest[i] = ft_strcjoin(env->variable, env->value, '=');
		if (!dest[i])
			return (ft_freetable(dest), ft_expend_malloc_faild(), NULL);
		i++;
		env = env->next;
	}
	dest[i] = NULL;
	return (dest);
}

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
	char	*dst;
	char	*dest;

	i = 0;
	env = NULL;
	while (o_env[i])
	{
		dest = ft_env_var(o_env[i]);
		dst = ft_env_val(o_env[i]);
		if (!dst || !dest)
			return (ft_clear_env(&env), free(dst), free(dest),
				ft_malloc_faild(), NULL);
		tmp = ft_lstnew_env(dest, dst);
		if (!tmp)
			return (ft_clear_env(&env), ft_malloc_faild(), NULL);
		ft_lstadd_back_env(&env, tmp);
		i++;
	}
	return (env);
}
