/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:32:27 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/21 04:14:05 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_wait(t_exec *execute)
{
	int	status;

	while (execute->next)
		execute = execute->next;
	waitpid(execute->child, &status, 0);
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(status))
		ft_status(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		ft_status(WTERMSIG(status) + 128);
	if (ft_status(-1) == 131)
		ft_putstr_fd(SIGQUIT_ERROR, 2);
	else if (ft_status(-1) == 130)
		write(1, "\n", 1);
}
