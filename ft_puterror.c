/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:17:05 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/30 22:57:27 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void ft_puterror(int flag)
{
	if (flag == 0)
		perror("minishell");
	else if (flag == 1)
		ft_putstr_fd(SQOT_ERROR, 2);
	else if (flag == 2)
		ft_putstr_fd(DQOT_ERROR, 2);
}
