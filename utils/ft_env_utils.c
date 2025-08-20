/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:48:18 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/20 12:07:01 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_env_val(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (ft_strdup(env + i + 1));
}

char	*ft_env_var(char *env)
{
	int	size;

	size = 0;
	while (env[size] && env[size] != '=')
		size++;
	return (ft_strndup(env, size));
}
