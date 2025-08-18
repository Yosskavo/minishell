/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:51:27 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/16 15:59:07 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_global_var(int i)
{
	static int	status;

	if (i != -1)
		status = i;
	return (status);
}

t_mini	*ft_global(t_mini *mini)
{
	static t_mini	*tmp;

	if (mini)
		tmp = mini;
	return (tmp);
}
