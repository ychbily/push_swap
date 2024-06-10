/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 03:37:33 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/10 18:28:17 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker_bonus.h"

int	main(int ac, char **av)
{
	t_ps	*a;
	t_ps	*b;
	char	*line;

	a = NULL;
	b = NULL;
	parse(ac, av, &a);
	line = get_next_line(0);
	while (line)
	{
		checker(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sort(a) == true && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
