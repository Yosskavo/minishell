/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 08:55:37 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 11:01:16 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_handle_sig(int sig)
{
	if (SIGINT == sig)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signal(void)
{
	if (signal(SIGINT, &ft_handle_sig) == SIG_ERR)
		return ((void)perror("minishell"));
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return ((void)perror("minishell"));
}

