/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:20:03 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/23 23:20:04 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_free_unset(t_env *env)
{
	free(env->variable);
	free(env->value);
	free(env);
}

static void	ft_env_unset(char *str)
{
	t_env	*env;

	env = ft_search_env_addr(str);
	if (!env)
		return ;
	if (env->next && env->previous)
	{
		env->previous->next = env->next;
		env->next->previous = env->previous;
	}
	else if (!(env->next))
		env->previous->next = NULL;
	else
	{
		env->next->previous = NULL;
		ft_global(NULL)->env = ft_global(NULL)->env->next;
	}
	return (ft_free_unset(env));
}

void	ft_unset(t_exec *execute)
{
	int	i;

	if (!(ft_global(NULL)->env))
		return ((void)ft_status(1));
	i = 1;
	while (execute->args[i])
	{
		ft_env_unset(execute->args[i]);
		i++;
	}
	ft_status(0);
}
