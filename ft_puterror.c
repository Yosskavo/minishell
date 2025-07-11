/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:17:05 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/11 15:45:10 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void ft_puterror_tocken(char *str, int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd(ERROR_OPPERATION, 2);
		ft_putstr_fd("\'", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\'\n", 2);
	}
	else if (flag == 1)
	{
		ft_putstr_fd(ERROR_TOCKEN, 2);
		ft_putstr_fd("\'", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\'\n", 2);
	}
}

void ft_tocken_error(t_parce *parce)
{
	if (parce->tocken == PIPE)
		ft_puterror_tocken(parce->str, 1);
	else if (parce->tocken == TOCKEN_ERROR)
	{
		if (!(parce->next))
			ft_puterror_tocken("newline", 1);
		else
			ft_puterror_tocken(parce->next->str, 1);
	}
	else if (parce->tocken == OPPERATION)
		ft_puterror(parce->str, 0);
}

void ft_puterror(int flag)
{
	if (flag == 0)
		perror("minishell");
	else if (flag == 1)
		ft_putstr_fd(SQOT_ERROR, 2);
	else if (flag == 2)
		ft_putstr_fd(DQOT_ERROR, 2);
}

