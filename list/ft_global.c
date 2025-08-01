/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:51:27 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/01 06:51:44 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_mini	*ft_global(t_mini *mini)
{
	static t_mini	*tmp;

	if (!mini)
		return (tmp);
	tmp = mini;
	return (tmp);
}
