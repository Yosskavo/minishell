/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:09:40 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/04 13:09:44 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetable(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		table[i] = NULL;
		i++;
	}
	free(table);
}
