/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:09:05 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 21:35:04 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static size_t	ft_elemint(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	int		j;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_elemint(n);
	j = n;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		n *= -1;
	str[i] = '\0';
	while (n > 0)
	{
		str[--i] = n % 10 + '0';
		n /= 10;
	}
	if (j < 0)
		*str = '-';
	return (str);
}
/*int main ()
{
		printf("%s",ft_itoa(1234));
		return (0);
}*/
