/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:17:05 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 15:59:12 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_put_malloced_error(char *s1, char *s2)
{
	char *dest;
	char *str;

	dest = ft_strjoin(s1, "\'");
	if (!dest)
		return (perror("minishell"), -1);
	str = ft_strjoin(dest, s2);
	free(dest);
	if (!str)
		return (perror("minishell"), -1);
	dest = ft_strjoin(str, "\'\n");
	free(str);
	if (!dest)
		return (perror("minishell"), -1);
	if (ft_putstr_fd(dest, 2) < 0)
		return (free(dest), perror("minishell"), -1);
	return (free(dest), 0);
}

static void	ft_puterror_tocken(char *str, int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd(OPPERATION_ERROR, 2);
		ft_putstr_fd("\'", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\'\n", 2);
	}
	else if (flag == 1)
	{
		ft_putstr_fd(TOCKEN_ERROR, 2);
		ft_putstr_fd("\'", 2);
		ft_putstr_fd(str, 2); 
		ft_putstr_fd("\'\n", 2);
	}
}

void	ft_tocken_error(t_parce *parce)
{
	if (parce->tocken == PIPE)
		ft_puterror_tocken(parce->str, 1);
	else if (parce->tocken != WORD && parce->tocken != ERROR_TOCKEN)
	{
		if (!(parce->next))
			ft_puterror_tocken("newline", 1);
		else
			ft_puterror_tocken(parce->next->str, 1);
	}
	else if (parce->tocken == ERROR_TOCKEN)
	{
		if (parce->previous && parce->previous->tocken != WORD)
			ft_puterror_tocken(parce->str, 1);
		else
			ft_puterror_tocken(parce->str, 0);
	}
}

void	ft_puterror(int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd(SQOT_ERROR, 2); 
	}
	else if (flag == 2)
	{
		ft_putstr_fd(DQOT_ERROR, 2);
	}
}
