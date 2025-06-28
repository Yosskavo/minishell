/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:19:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/28 09:42:18 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_puterror(int flag, char c)
{
	char *str;
	
	str = NULL;
	if (flag == 0)
		perror("minishell");
	else if (flag == 1)
	{
		if (c == '\'')
			ft_putstr_fd(SQOT_ERROR, 2);
		else
			ft_putstr_fd(DQOT_ERROR, 2);
	}
	return (-1);
}
