/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:58:17 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 09:28:49 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_env_unset(char *str)
{
	t_env	*env;
	t_env	*tmp;

	tmp = ft_global(NULL)->env;
	env = tmp->next;
	if (!ft_strcmp(str, env->variable))
		return (ft_free_env(tmp), ft_global(NULL)->env = env);
	while (env)
	{
		tmp = env->next;
		if (!ft_strcmp(tmp->variable, str))
			return ();
		env = tmp;
	}
}

int	ft_unset(t_exec *execute)
{
	int	i;

	i = 1;
	while (execute->args[i])
	{
		ft_env_unset(execute->args[i]);
		i++;
	}
	return (0);
}
