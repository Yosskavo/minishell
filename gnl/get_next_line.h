/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:24:32 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/31 08:24:37 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # include <stdlib.h>
// # include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strrest(char *str);
char	*ft_strline(char *str);
char	*ft_strread(int fd, char *dest);
size_t	ft_whereline(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
