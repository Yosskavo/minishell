/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 04:46:45 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/16 15:00:49 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_many_tocken(t_parce *parce, t_tocken tocken)
{
	int	size;

	size = 0;
	while (parce)
	{
		if (parce->tocken == tocken)
			size++;
		parce = parce->next;
	}
	return (size);
}

int	ft_many_tocken_between_tocken(t_parce *parce, t_tocken tocken,
		t_tocken delimeter)
{
	int	size;

	size = 0;
	while (parce && parce->tocken != delimeter)
	{
		if (parce->tocken == tocken)
			size++;
		parce = parce->next;
	}
	return (size);
}
