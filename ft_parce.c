/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:05:51 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/01 14:45:31 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_parcing(char *str)
{
	t_parce *parce;

	parce = NULL;
	if (ft_spliting(str, &parce) == -1)
		return (-1);
	// ft_print_it(parce);
	// ft_clear_list(&parce);
	ft_tokenisation(&parce);
	// ft_expanding(parce);
	return (0);
}
