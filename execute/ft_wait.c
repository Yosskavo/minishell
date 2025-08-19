/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:32:27 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/19 05:32:29 by nel-khol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_wait(t_exec *execute)
{
	int	status;

	status = 0;
	while (execute)
	{
		waitpid(execute->child, &status, 0);
		execute = execute->next;
	}
	// wait(NULL);
	if (WIFEXITED(status))
		ft_status(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		ft_status(WTERMSIG(status) + 128);
	if (ft_status(-1) == 131)
		ft_putstr_fd(SIGQUIT_ERROR, 2);
	else if (ft_status(-1) == 130)
		write(1, "\n", 1);
}
