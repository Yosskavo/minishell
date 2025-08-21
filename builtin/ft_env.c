/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:55:25 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/21 05:32:27 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_env(void)
{
	t_env	*env;

	env = ft_global(NULL)->env;
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->variable, env->value);
		env = env->next;
	}
	ft_status(0);
}
