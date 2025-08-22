/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:28:13 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 05:22:43 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_clear_all(void)
{
	t_mini	*mini;

	mini = ft_global(NULL);
	ft_clear_exec(&(mini->execute));
	ft_clear_env(&(mini->env));
	if (mini->old_fd > -1)
		close(mini->old_fd);
	if (mini->fd[0] > -1)
		close(mini->fd[0]);
	if (mini->fd[1] > -1)
		close(mini->fd[1]);
}

void	ft_clear(void)
{
	ft_clear_all();
	free(ft_global(NULL));
}
