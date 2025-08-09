/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:44:47 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/09 17:14:49 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_duptwo(t_tocken tocken, int fd)
{
	int	flag;

	if (fd == -2)
		return (ft_putstr_fd(AMBIGUOUS_ERROR, 2), -2);
	if (fd == -1)
		return (perror("minishell"), -1);
	if (tocken == HEREDOC || tocken == REDIRACTION)
		flag = dup2(STDIN_FILENO, fd);
	else if (tocken == APPEND || tocken == OVERWRITE)
		flag = dup2(STDOUT_FILENO, fd);
	if (flag < 0)
		return (close(fd), -1);
	return (0);
}

static int	ft_open(t_parce *tmp)
{
	int	flag;

	if (tmp->tocken == HEREDOC)
		return (tmp->fd_out);
	if (tmp->next->tocken == AMBIGUOUS)
		return (-2);
	if (tmp->tocken == APPEND)
		flag = open(tmp->next->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tmp->tocken == OVERWRITE)
		flag = open(tmp->next->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp->tocken == REDIRACTION)
		flag = open(tmp->next->str, O_RDONLY);
	if (flag < 0)
		return (-1);
	return (flag);
}

int	ft_redi(t_exec *execute)
{
	t_parce	*tmp;
	int		flag;

	tmp = exectute->redi;
	while (tmp)
	{
		flag = ft_duptwo(tmp->tocken, ft_open(tmp));
		if (flag < 0)
			return (flag);
		tmp = tmp->next;
		if (tmp && tmp->tocken == FILENAME)
			tmp = tmp->next;
	}
	return (0);
}
