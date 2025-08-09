/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:51:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/09 17:30:46 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	**ft_original_fd(void)
{
	static int	fd[2];

	return (&fd);
}

void	ft_restor_fd(void)
{
	int	*fd;

	fd = *ft_original_fd();
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	ft_dup(void)
{
	int	**fd_orig;
	int	fd[2];

	fd_orig = ft_original_fd();
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	*fd_orig[0] = fd[0];
	*fd_orig[1] = fd[0];
}
