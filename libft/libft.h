/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:31:48 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/26 01:44:58 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strstr(char *big_str, char *small_str);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
size_t	ft_lengh_of_table(char **table);
char	*ft_strdup(char *str);
char	*ft_itoa(int n);
void	ft_freetable(char **table);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strndup(char *str, int size);
char	*ft_strncmp(char *str, char *s, int size);
int		ft_isalnum(int c);
char	*ft_strchr(const char *str, int c);

#endif
