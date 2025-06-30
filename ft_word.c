/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:16:24 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/30 10:17:50 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int ft_tell_space(char *str)
{
	int i;

	i = 1;
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
	return (i + 1);
}

int ft_word(t_parce **parce, char *s, int *pos)
{
	char *dest;
	int		i;

	dest = malloc(ft_tell_space(s + (*pos) + 1));
	if (!dest)
		return (ft_puterror(0), -1);
	i = 0;
	while (s[*pos] && !(s[*pos] == ' ' || (s[*pos] >= 9 && s[*pos] <= 13)))
	{
		dest[i] = s[*pos];
		i++;
		(*pos)++;
	}
	dest[i] = '\0';
	if (!ft_list_add_back(parce, ft_newlist(dest)))
		return (ft_puterror(0), -1);
	return (0);
}
