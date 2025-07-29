/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expantion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:10:46 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/27 10:12:51 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_valid_expention(char *str)
{
	if (str[0] == '_' || ft_isalnum(str[0]) || str[0] == '?')
		return (1);
	return (0);
}

void	ft_fullmap_expand(t_expend *exp, char *flag, int size)
{
	int		i;
	char	*dest;

	i = 0;
	while (i < size)
	{
		dest = ft_strjoin(exp->map, flag);
		if (!dest)
			return (perror("minishell"));
		free(exp->map);
		exp->map = dest;
		i++;
	}
}
