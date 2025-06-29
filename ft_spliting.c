/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:31:55 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/29 11:32:05 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int ft_tell_space(char *str)
{
	int i;

	i = 1;
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
	return (i + 1);
}

void ft_print_it(t_parce *parce)
{
	while (parce)
	{
		printf("%s\n", parce->str);
		parce = parce->next;
	}
}

int ft_word(t_parce **parce, char *s, int *pos)
{
	char *dest;
	int		i;

	dest = malloc(ft_tell_space(s + (*pos) + 1));
	if (!dest)
		return (-1);
	i = 0;
	while (s[*pos] && !(s[*pos] == ' ' || (s[*pos] >= 9 && s[*pos] <= 13)))
	{
		dest[i] = s[*pos];
		i++;
		(*pos)++;
	}
	dest[i] = '\0';
	if (!ft_list_add_back(parce, ft_newlist(dest)))
		return (-1);
	return (0);
}

int ft_spliting(char *str, t_parce *parce)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (ft_word(&parce, str, &i) == -1)
			return (ft_clear_list(&parce), -1);
	}
	ft_print_it(parce);
	return (0);
}