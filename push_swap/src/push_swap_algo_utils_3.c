/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:27:19 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:41:59 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	start_working(t_ps *a, t_ps *b)
{
	indexing(a);
	indexing(b);
	find_target_for_a(a, b);
	find_cost(a, b);
	find_cheapest(a);
}

void	finish_working(t_ps *a, t_ps *b)
{
	indexing(a);
	indexing(b);
	find_target_for_b(a, b);
}

void	start_pushing_to_b(t_ps **a, t_ps **b)
{
	t_ps	*cheapest_node;

	cheapest_node = chpst_node(*a);
	(cheapest_node->median && cheapest_node->target_node->median)
	&& (rotate_both(a, b, cheapest_node), 0);
	(!(cheapest_node->median) && !(cheapest_node->target_node->median))
	&& (rev_rotate_both(a, b, cheapest_node), 0);
	checking_before_pushing(a, cheapest_node, 'a');
	checking_before_pushing(b, cheapest_node->target_node, 'b');
	pb(b, a, 1);
}

void	bring_min_to_top(t_ps **a)
{
	int	min;

	min = min_value(*a)->value;
	if ((*a)->median)
		while ((*a)->value != min)
			ra(a, 1);
	else
		while ((*a)->value != min)
			rra(a, 1);
}

void	returning_values(t_ps **a, t_ps **b)
{
	checking_before_pushing(a, (*b)->target_node, 'a');
	pa(a, b, 1);
}
