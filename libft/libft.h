/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:36:59 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/13 14:56:37 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);
char	*ft_strstr(char *big_str, char *small_str);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
size_t	ft_lengh_of_table(char **table);
char	*ft_strdup(char *str);
char	*ft_itoa(int n);
void	ft_freetable(char **table);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
