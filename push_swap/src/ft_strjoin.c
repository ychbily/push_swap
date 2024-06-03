/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:27:15 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:41:51 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	if (!dst && dstsize == 0)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	j = dstlen;
	i = 0;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while ((dstlen + i) < dstsize - 1 && src[i] != '\0' )
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len1 + 1);
	ft_strlcat(ptr, s2, len + 1);
	return (ptr);
}
