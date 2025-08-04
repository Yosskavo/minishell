/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:05:15 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/04 16:18:29 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_handle_sig(int sig)
{
	if (SIGINT == sig && !ft_global_var(-1))
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
