/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 06:03:32 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/02 23:01:07 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indexing(t_ps *a)
{
	int	i;
	int	median;

	if (!a)
		return ;
	i = 0;
	median = stack_len(a) / 2;
	while (a)
	{
		a->index = i;
		((i <= median) && (a->median = true)) || (a->median = false);
		a = a->next;
		i++;
	}
}

void	find_target(t_ps *a, t_ps *b)
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

void	find_cost(t_ps *a, t_ps *b)
{
	int	len_a;
	int	len_b;

	if (!a || !b)
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		if (b->median)
			b->cost = b->index;
		else
			b->cost = len_b - b->index;
		if (b->target_node->median)
			b->cost += b->target_node->index;
		else
			b->cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	find_cheapest(t_ps *b)
{
	long	cheapest;
	t_ps	*cheapest_node;

	if (!b)
		return ;
	cheapest = LONG_MAX;
	while (b)
	{
		(b->cost < cheapest) && (cheapest = b->cost, cheapest_node = b);
		b = b->next;
	}
	cheapest_node->cheapest = true;
}
