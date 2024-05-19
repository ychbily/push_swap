/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 06:04:40 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:41:56 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_ps **a, t_ps **b, t_ps *cheapest_node)
{
	while ((*b) != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, 1);
	indexing(*a);
	indexing(*b);
}

void	checking_before_pushing(t_ps **head, t_ps *cheapest_node, char c)
{
	while ((*head)->value != cheapest_node->value)
	{
		if (c == 'a')
		{
			if (cheapest_node->median == true)
				ra(head, 1);
			else
				rra(head, 1);
		}
		else if (c == 'b')
		{
			if (cheapest_node->median == true)
				rb(head, 1);
			else
				rrb(head, 1);
		}
	}
}

void	rev_rotate_both(t_ps **a, t_ps **b, t_ps *cheapest_node)
{
	while ((*b) != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, 1);
	indexing(*a);
	indexing(*b);
}

void	find_target_for_b(t_ps *a, t_ps *b)
{
	t_ps		*current;
	t_ps		*target;
	long		best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current = a;
		while (current)
		{
			(current->value > b->value && current->value < best_match)
			&& (best_match = current->value, target = current);
			current = current->next;
		}
		((best_match == LONG_MAX) && (b->target_node = min_value(a)))
		|| (b->target_node = target);
		b = b->next;
	}
}
