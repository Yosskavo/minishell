/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:47:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/14 08:55:01 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"


static void ft_read_herdoc(t_parce *tmp)
{
	char *str;

	while (1)
	{
		str = readline("->");
		if (!str)
			return (0);
		if (ft_strcmp(str, tmp->str))
			return (0);
		if (!*str)
			ft_join_herdoc_file("\n");
		else 
			ft_join_herdoc_file(ft_strjoin(str, "\n"));
	}
}


static char	*ft_random_file(void)
{
	int byte;
	char	*c;

	fd = open("/dev/random", O_RDONLY);
	if (fd < -1)
		return (NULL);
	c = malloc(5);
	if (!c)
		return (close(fd), NULL);
	if (read(fd, c, 4) < 0)
		return (close(fd), free(c), NULL);
	close(fd);
	c[4] = '\0';
	fd = c[0] + c[1] + c[2] + c[3];
	free(c);
	c = ft_itoa(byte);
	return (c);
}

static void *ft_start_heredoc(t_parce *tmp)
{
	char	*filename;

	filename = ft_strjoin("/tmp/", ft_random_file());
	if (!filename)
		return (NULL);
	tmp->fd_out = open(file, O_CREAT | O_RDONLY);
	tmp->fd_in = open(file, O_WRONLY);
	if (tmp->fd_out < 0 || tmp->fd_in < 0)
		return (free(filename), NULL);
	unlink(filename);
	free(filename);
	return ((void *)tmp);
}

static void *ft_fork_heredoc(t_parce *tmp)
{
	int	child;
	int status;

	child = fork();
	if (child < 0)
		return (perror("minishell"), NULL);
	if (child == 0)
	{
		ft_read_herdoc(tmp->next);
	}
	else
	{
		wait(&status);
		WEXITSTATUS(status);
	}
}

static void ft_handle_heredoc(t_parce *tmp)
{
	if (!ft_start_heredoc(tmp))
		return (perror("minishell"));
	ft_fork_heredoc(tmp->previous);
}


int	ft_heredoc(t_parce *parce)
{
	t_pacre *tmp;

	tmp = parce;
	while (tmp)
	{
		if (tmp->tocken == DELEMITER)
			ft_handle_heredoc(tmp);
		tmp = tmp->next;
	}
	return (0);
}
