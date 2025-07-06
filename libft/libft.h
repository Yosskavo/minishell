/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:36:59 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/05 22:24:30 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define LIBFT_H

# include <unistd.h>

void ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
char *ft_strstr(char *big_str, char *small_str);
int	ft_isalnum(int c);
int	ft_isdigit(int c);
int	ft_isalpha(int c);
#endif
