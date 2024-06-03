/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:27:19 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 15:15:12 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_working(t_ps *a, t_ps *b)
{
	indexing(a);
	indexing(b);
	find_target(a, b);
	find_cost(a, b);
	find_cheapest(b);
}

void	finish_working(t_ps **a, t_ps **b)
{
	t_ps	*cheapest_a_node;
	t_ps	*cheapest_b_node;

	cheapest_b_node = chpst_node(*b);
	if (!cheapest_b_node)
		return ;
	cheapest_a_node = cheapest_b_node->target_node;
	(cheapest_a_node->median && cheapest_b_node->median)
	&& (rotate_both(a, b, cheapest_b_node), 0);
	(!(cheapest_a_node->median) && !(cheapest_b_node->median))
	&& (rev_rotate_both(a, b, cheapest_b_node), 0);
	checking_before_pushing(a, cheapest_a_node, 'a');
	checking_before_pushing(b, cheapest_b_node, 'b');
	pa(a, b, 1);
}

void	bring_min_to_top(t_ps **a)
{
	t_ps	*min;

	min = min_value(*a);
	if (min->median)
		while (*a != min)
			ra(a, 1);
	else
		while (*a != min)
			rra(a, 1);
}
