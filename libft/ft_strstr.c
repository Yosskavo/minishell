/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:05:32 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/04 13:05:32 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_strstr(char *big_str, char *small_str)
{
	int	i;
	int	j;

	i = 0;
	while (big_str[i])
	{
		j = 0;
		while (big_str[i + j] && small_str[j] == big_str[i + j])
			j++;
		if (!small_str[j])
			return (big_str + i);
		i++;
	}
	return (NULL);
}
