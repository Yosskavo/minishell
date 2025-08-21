/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 06:39:23 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/21 04:00:10 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	ft_perror(char *str)
{
	char	*dest;
	char	*s;

	dest = ft_strjoin("minishell : ", str);
	if (!dest)
		ft_expend_malloc_faild();
	s = ft_strjoin(dest, NAR_ERROR);
	if (!dest)
		return (free(dest), ft_expend_malloc_faild());
	free(dest);
	ft_putstr_fd(s, 2);
	free(s);
}

static int	ft_help(char **args, int i, int sign)
{
	int	j;

	j = i;
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
			return (-1);
		i++;
	}
	if (args[2])
		return (-2);
	i = ft_atoi(args[1] + j) * sign;
	return ((unsigned char)(i));
}

static int	ft_exit_check(char **args)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	while (args[1][i] == ' ' || (args[1][i] >= 9 && 13 >= args[1][i]))
		i++;
	if (args[1][i] == '-' || args[1][i] == '+')
		if (args[1][i++] == '-')
			sign = -1;
	res = ft_strlen(args[1] + i);
	if (res > 19)
		return (-1);
	if (res == 19)
	{
		if (sign != -1 && ft_strcmp(args[1] + i, MAX_EXIT) < 0)
			return (-1);
		if (sign == -1 && ft_strcmp(args[1] + i, MIN_EXIT) < 0)
			return (-1);
	}
	return (ft_help(args, i, sign));
}

void	ft_exit(t_exec *execute)
{
	int	flag;

	flag = 0;
	if (isatty(1) && isatty(0))
		ft_putendl_fd("exit", 2);
	if (!(execute->args[1]))
		flag = ft_status(-1);
	else
		flag = ft_exit_check(execute->args);
	if (flag == -1)
	{
		ft_perror(execute->args[1]);
		flag = 2;
	}
	else if (flag == -2)
	{
		ft_putstr_fd(TMA_ERROR, 2);
		ft_status(1);
		return ;
	}
	ft_clear();
	exit(flag);
}
