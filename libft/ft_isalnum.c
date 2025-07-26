/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:27:22 by yel-mota          #+#    #+#             */
/*   Updated: 2024/11/07 13:53:23 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
/*int main()
 * {
 * 	if (ft_islnum('a') == 1)
 * 		printf("yeahh for sure");
 * 	else
 * 		printf("yeaaahh for not sure");
 *	return (0);
 * }
 */
