/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:41:23 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 22:05:40 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_wait(int child)
{
	int	status;

	status = 0;
	waitpid(child, &status, 0);
	wait(NULL);
	if (WIFEXITED(status))
		ft_status(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		ft_status(WTERMSIG(status) + 128);
	if (ft_status(-1) == 131)
		ft_putstr_fd(SIGQUIT_ERROR, 2);
	else if (ft_status(-1) == 130)
		write(1, "\n", 1);
}
