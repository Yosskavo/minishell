/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:51:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/16 16:19:10 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_restor_fd(void)
{
	dup2(ft_global(NULL)->fd[0], STDIN_FILENO);
	dup2(ft_global(NULL)->fd[1], STDOUT_FILENO);
	close(ft_global(NULL)->fd[0]);
	close(ft_global(NULL)->fd[1]);
	ft_global(NULL)->fd[0] = -1;
	ft_global(NULL)->fd[0] = -1;
	return (1);
}

int	ft_dup(void)
{
	ft_global(NULL)->fd[0] = dup(STDIN_FILENO);
	ft_global(NULL)->fd[1] = dup(STDOUT_FILENO);
	if (ft_global(NULL)->fd[0] < 0 || ft_global(NULL)->fd[1] < 0)
	{
		if (ft_global(NULL)->fd[0] > -1)
			close(ft_global(NULL)->fd[0]);
		if (ft_global(NULL)->fd[1] > -1)
			close(ft_global(NULL)->fd[1]);
		return (0);
	}
	return (1);
}
