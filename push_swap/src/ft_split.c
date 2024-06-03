/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:10:56 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/01 21:40:42 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	counter_str(char const *s, char c)
{
	int	count;
	int	str;

	count = 0;
	str = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			str = 0;
		else if (str == 0)
		{
			str = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	**rtrn(char **ptr, int j)
{
	while (j > 0)
	{
		j--;
		free(ptr[j]);
	}
	free(ptr);
	return (NULL);
}

static char	**sp(char const *s, char c, int counted, char **ptr)
{
	int	j;
	int	i;

	j = 0;
	while (j < counted)
	{
		i = 0;
		while (s[i] != 0 && s[i] == c)
			s++;
		while (s[i] != 0 && s[i] != c)
			i++;
		ptr[j] = ft_calloc(i + 1, 1);
		if (ptr[j] == NULL)
			return (rtrn(ptr, j));
		ft_strlcpy(ptr[j], s, i + 1);
		s += i;
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		counted;

	counted = counter_str(s, c);
	if (!s)
		return (NULL);
	ptr = ft_calloc(counted + 1, sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	ptr = sp(s, c, counted, ptr);
	if (!ptr)
	{
		free_ptr(ptr);
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
