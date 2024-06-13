/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 03:38:32 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 21:54:08 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "libc.h"

char	*get_next_line(int fd);
char	*f_dup(char *str, int len);
char	*ft_append(char *s1, char *s2);
int		new_ln(char *buf);
char	*ft_line(char **buf);	

#endif