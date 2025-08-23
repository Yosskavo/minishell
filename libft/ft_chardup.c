/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chardup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 03:28:24 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/22 03:30:19 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_chardup(char c)
{
	char	*dest;

	dest = malloc(2);
	if (!dest)
		ft_malloc_faild();
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}
