/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:31:55 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/30 23:04:39 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void ft_print_it(t_parce *parce)
{
	while (parce)
	{
		printf("%s\n", parce->str);
		parce = parce->next;
	}
}

int ft_spliting(char *str, t_parce *parce)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if ((str[i] == '\"' || str[i] == '\''))
		{	
			if (ft_qots(&parce, str, &i) == -1)
				return (ft_clear_list(&parce), -1);
		}
		else if (ft_word(&parce, str, &i) == -1)
			return (ft_clear_list(&parce), -1);
	}
	ft_print_it(parce);
	return (0);
}
