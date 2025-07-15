/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:47:54 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 13:10:14 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static char	*ft_random_file(void)
{
	int fd;
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
	c = ft_itoa(fd);
	return (c);
}

static void *ft_start_heredoc(t_parce *tmp)
{
	char	*filename;

	filename = ft_strjoin("/tmp/", ft_random_file());
	if (!filename)
		return (NULL);
	tmp->fd_out = open(filename, O_CREAT, 0777);
	if (tmp->fd_out < 0)
		return (free(filename), NULL);
	tmp->fd_out = open(filename, O_RDONLY);
	if (tmp->fd_out < 0)
		return (free(filename), NULL);
	tmp->fd_in = open(filename, O_WRONLY);
	if (tmp->fd_out < 0)
		return (free(filename), NULL);
	unlink(filename);
	free(filename);
	return ((void *)tmp);
}

static void ft_handle_heredoc(t_parce *tmp)
{
	if (!ft_start_heredoc(tmp))
		return (perror("minishell"));
	ft_fork_heredoc(tmp->previous);
}

int	ft_heredoc(t_parce *parce)
{
	t_parce *tmp;

	tmp = parce;
	while (tmp)
	{
		if (tmp->tocken == DELEMITER)
			ft_handle_heredoc(tmp);
		tmp = tmp->next;
	}
	return (0);
}

