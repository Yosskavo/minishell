/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:53:32 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/03 17:27:12 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static char	*ft_expend_heredoc_search(char *str, int size)
{
	t_env	*env;
	int		i;

	i = 0;
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

void	ft_expend_heredoc(char *str, int *i, int fd)
{
	int		size;
	char	*dest;

	(*i)++;
	size = ft_env_var_size(str + *i);
	dest = ft_expend_heredoc_search(str + *i, size);
	if (dest)
		ft_putstr_fd(dest, fd);
	(*i) += size;
}
