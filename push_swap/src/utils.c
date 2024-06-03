/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:46:45 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:42:13 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}

bool	check_sort(t_ps *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	stack_len(t_ps *a)
{
	int	counter;

	if (!a)
		return (1);
	counter = 0;
	while (a)
	{
		counter++;
		a = a->next;
	}
	return (counter);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0' )
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
