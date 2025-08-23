/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:19:19 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/23 23:19:20 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_env(void)
{
	t_env	*env;

	env = ft_global(NULL)->env;
	if (!env)
		return ((void)ft_status(1));
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->variable, env->value);
		env = env->next;
	}
	ft_status(0);
}
