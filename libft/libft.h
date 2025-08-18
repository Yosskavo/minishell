/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:31:48 by yel-mota          #+#    #+#             */
/*   Updated: 2025/08/18 02:52:54 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// this some function from libft

int		ft_valid_input(char *str);
char	*ft_strcjoin(char *so, char *ss, char c);
char	*ft_strnjoin(char const *s1, char const *s2, size_t size);
int		ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char c, int fd);
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
int		ft_strncmp(const char *str, const char *s, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isalnum(int c);
char	*ft_strchr(const char *str, int c);
char	**ft_split(const char *str, char c);
#endif
