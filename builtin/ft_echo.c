/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-khol <nel-khol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 05:54:32 by nel-khol          #+#    #+#             */
/*   Updated: 2025/08/21 02:25:40 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (1);
	i++;
	while (str[i] == 'n')
	{
		i++;
		if (!str[i])
			return (0);
	}
	return (1);
}

void	ft_echo(t_exec *execute)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (execute->args[i])
	{
		if (ft_newline(execute->args[i]))
			break ;
		newline = 0;
		i++;
	}
	while (execute->args[i])
	{
		ft_putstr_fd(execute->args[i], 1);
		if (execute->args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (newline)
		printf("\n");
	ft_status(0);
}
