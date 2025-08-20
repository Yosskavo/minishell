/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 01:38:33 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/20 01:41:55 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_listsize_env(void)
{
	t_env	*env;
	int		i;

	i = 0;
	env = ft_global(NULL)->env;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}
