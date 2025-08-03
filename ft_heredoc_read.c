/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 09:57:30 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/03 16:58:21 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_free_all_heredoc(void)
{
	t_mini	*mini;

	mini = ft_global(NULL);
	ft_clear_env(&(mini->env));
	ft_mini_clear_list(&(mini->start));
	free(mini->str);
	free(mini);
	rl_clear_history();
}

static void	ft_write_heredoc(char *str, int fd)
{
	int	i;

	i = 0;
	printf("%zu\n", ft_strlen(str));
	while (str[i])
	{
		if (str[i] == '$' && ft_valid_expention(str[i + 1]) == 2)
			ft_expend_heredoc(str, &i, fd);
		else
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
	printf("%d\n", i);
	ft_putchar_fd('\n', fd);
}

void	ft_read_herdoc(t_parce *tmp)
{
	char	*str;

	while (1)
	{
		str = readline("->");
		if (!str)
			return (ft_free_all_heredoc(), (void)ft_putstr_fd(HEREDOC_ERROR,
					2));
		if (!ft_strcmp(str, tmp->next->str))
			return (free(str), ft_free_all_heredoc());
		if (!*str)
			ft_putstr_fd("\n", tmp->fd_in);
		else
		{
			if (!tmp->next->qoted)
				ft_write_heredoc(str, tmp->fd_in);
			else
			{
				ft_putstr_fd(str, tmp->fd_in);
				ft_putstr_fd("\n", tmp->fd_in);
			}
		}
		free(str);
	}
}
