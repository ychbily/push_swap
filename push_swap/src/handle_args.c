/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:42:24 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/19 00:54:41 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
