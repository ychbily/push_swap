/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:42:48 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/19 00:44:30 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*str;
	char	**splited;
	t_ps	*a;
	t_ps	*b;

	a = NULL;
	b = NULL;
	(ac == 1 || (ac == 2 && !av[1][0]))
		&& (write(2, "Error\n", 6), exit(1), 0);
	str = handle_args(av, ac);
	splited = ft_split(str, ' ');
	stack_init(&a, splited);
	if (!check_sort(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap_algo(&a, &b);
	}
	free_stack(&a);
	free(str);
	free_ptr(splited);
	free(splited);
}
