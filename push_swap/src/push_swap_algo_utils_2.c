/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 06:04:40 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 21:50:06 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both(t_ps **a, t_ps **b, t_ps *cheapest_node)
{
	while ((*b) != cheapest_node && *a != cheapest_node->target_node)
		rr(a, b, 1);
	while ((*b) != cheapest_node)
		rb(b, 1);
	while ((*a) != cheapest_node->target_node)
		ra(a, 1);
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
	while ((*b) != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b, 1);
	while ((*b) != cheapest_node)
		rrb(b, 1);
	while ((*a) != cheapest_node->target_node)
		rra(a, 1);
	indexing(*a);
	indexing(*b);
}
