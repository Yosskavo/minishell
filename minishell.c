/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:12:11 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/29 11:29:35 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_start(void)
{
	char *str;

	while (1)
	{
		str = readline("mini-->");
		if (!str)
			return (-1);
		if (*str)
			ft_parcing(str);
		free(str);
	}
	return (0);
}

int main ()
{
	ft_start();
}