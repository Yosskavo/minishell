/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:34:18 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/15 13:57:25 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
char	*get_next_line(int fd);
char	*ft_strrest(char *str);
char	*ft_strline(char *str);
char	*ft_strread(int fd, char *dest);
size_t	ft_whereline(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
