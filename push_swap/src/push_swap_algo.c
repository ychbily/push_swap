/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:10:44 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/28 00:46:22 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_algo_helper(t_ps **a, t_ps **b)
{
	int	i;
	int	median;

	while (stack_len(*a) > 3)
	{
		i = 0;
		median = find_median(*a);
		(median == -1) && (write(2, "ERROR\n", 6), 0);
		while (i < stack_len(*a))
		{
			if ((*a)->value < median)
				pb(b, a, 1);
			else
				ra(a, 1);
			i++;
		}
	}
}

void	push_swap_algo(t_ps **a, t_ps **b)
{
	push_algo_helper(a, b);
	(!check_sort(*a)) && (tiny_sort(a), 0);
	while (*b)
	{
		start_working(*a, *b);
		finish_working(a, b);
	}
	indexing(*a);
	bring_min_to_top(a);
}
