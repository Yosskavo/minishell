/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executable_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 03:36:10 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/17 08:16:06 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_execute_creat_path(t_exec *execute)
{
	char	*path;
	char	**table;
	int		i;

	path = ft_execute_search_expend(PATH);
	if (!path)
		return (execute->error = ERROR_X, (void)1);
	table = ft_split(path, ':');
	if (!table)
		ft_expend_malloc_faild();
	i = 0;
	while (table[i])
	{
		path = ft_pathjoin(table[i], execute->args[0]);
		if (!ft_check(execute, path))
			return ;
		i++;
	}
}
