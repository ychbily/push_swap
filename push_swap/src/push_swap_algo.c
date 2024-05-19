/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:10:44 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:42:02 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap_algo(t_ps **a, t_ps **b)
{
	int	len;

	len = stack_len((*a));
	(len > 3 && !check_sort((*a))) && (pb(b, a, 1), len--, 0);
	(len > 3 && !check_sort((*a))) && (pb(b, a, 1), len--, 0);
	while (len > 3 && !check_sort((*a)))
	{
		start_working(*a, *b);
		start_pushing_to_b(a, b);
		len--;
	}
	(!check_sort(*a)) && (tiny_sort(a), 0);
	while (*b)
	{
		finish_working(*a, *b);
		returning_values(a, b);
	}
	indexing(*a);
	bring_min_to_top(a);
}
