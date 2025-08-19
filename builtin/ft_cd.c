/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:53:35 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 11:47:26 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_cd(t_exec *execute)
{
	char	*dest;

	if (!(execute->args[1]))
	{
		dest = ft_search_expend("HOME", ft_strlen("HOME"));
		if (!dest)
			return (ft_status(1), ft_putstr_fd(CD_HOME_ERROR, 2), (void)1);
		if (chdir(dest))
			return (ft_status(1), perror("minishell"), (void)1);
	}
	if (chdir(execute->args[1]))
		return (ft_status(2), perror("minishell"));
	// ft_update_env();
	ft_status(0);
}
