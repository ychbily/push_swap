/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:42:24 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/07 16:52:39 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_empty_or_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

static char	*ft_strdup(const char *s1)
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

char	*handle_args(char **av, int ac)
{
	char	*tmp;
	char	*str0;
	int		i;

	str0 = ft_strdup("");
	if (ac >= 2)
	{
		i = 1;
		while (av[i])
		{
			(ft_strlen(av[i]) == 0 || is_empty_or_spaces(av[i]))
				&& (free(str0), write(2, "Error\n", 6), exit(1), 0);
			(i > 1) && (tmp = ft_strjoin(str0, " "), free(str0), str0 = tmp);
			tmp = ft_strjoin(str0, av[i++]);
			free(str0);
			str0 = tmp;
		}
	}
	return (str0);
}
