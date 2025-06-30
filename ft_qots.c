/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 07:58:48 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/30 23:07:08 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_qots_end(char *str)
{
	int	i;
	char c;
	int	flag;

	if (*str == '\"')
	{
		c = '\"';
		flag = 2;
	}
	else 
	{
		c = '\'';
		flag = 1;
	}
	i = 1;
	while (str[i] != c)
	{
		if (!str[i])
			return (ft_puterror(flag), -1);
		i++;
	}
	return (0);
}

int ft_size_string(char *str)
{
	int	i;
	char c;

	if (*str == '\"')
		c = '\"';
	else 
		c = '\'';
	i = 1;
	while (str[i] != c)
		i++;
	return (i);
}

char	*ft_strcpy_tell_qot(char *str, int *pos)
{
	char *dest;
	int		i;
	char	c;

	dest = malloc(ft_size_string(str + *(pos)));
	if (!dest)
		return (NULL);
	if (str[*pos] == '\'')
		c = '\'';
	else
		c = '\"';
	i = 0;
	(*pos)++;
	while (str[*pos] != c)
	{
		dest[i] = str[*pos];
		(*pos)++;
		i++;
	}
	(*pos)++;
	dest[i] = '\0';
	return (dest);
}

int ft_qots(t_parce **parce, char *str, int *i)
{
	char *dest;

	if (ft_qots_end(str + *i) == -1)
		return (-1);
	dest = ft_strcpy_tell_qot(str, i);
	if (!dest)
		return (ft_puterror(0), -1);
	if (!ft_list_add_back(parce, ft_newlist(dest)))
		return (-1);
	return (0);
}