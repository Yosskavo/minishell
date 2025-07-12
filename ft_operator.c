/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:31:05 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/12 08:26:14 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_operator_size(char *str)
{
	char	c;
	int		i;

	i = 0;
	c = *str;
	while (str[i] == c)
		i++;
	return (i);
}

int	ft_split_operator(t_parce **parce, char *str, int *i)
{
	char	*dest;
	int		j;
	char	c;

	while (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
	{
		dest = malloc(ft_operator_size(str + (*i)) + 1);
		if (!dest)
			return (ft_puterror(0), -1);
		j = 0;
		c = str[*i];
		while (c == str[*i])
		{
			dest[j] = str[*i];
			(*i)++;
			j++;
		}
		dest[j] = '\0';
		if (!ft_list_add_back(parce, ft_newlist(dest)))
			return (ft_puterror(0), -1);
	}
	return (0);
}
