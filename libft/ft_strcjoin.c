/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:24:35 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 02:47:07 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char *so, char *ss, char c)
{
	char	*dest;
	int		i;

	dest = malloc(ft_strlen(so) + ft_strlen(ss) + 2);
	if (!dest)
		return (NULL);
	i = 0;
	while (*so)
	{
		dest[i] = *so;
		so++;
		i++;
	}
	dest[i++] = c;
	while (*ss)
	{
		dest[i] = *ss;
		ss++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
