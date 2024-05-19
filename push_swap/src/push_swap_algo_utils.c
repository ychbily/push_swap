/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 06:03:32 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:42:01 by ychbily          ###   ########.fr       */
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
		((i < median) && (a->median = true)) || (a->median = false);
		a = a->next;
		++i;
	}
}

void	find_target_for_a(t_ps *a, t_ps *b)
{
	t_ps	*current;
	t_ps	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MAX;
		current = b;
		while (current)
		{
			(current->value < a->value && current->value > best_match)
			&& (best_match = current->value, target = current);
			current = current->next;
		}
		((best_match == LONG_MAX) && (a->target_node = max_value(b)))
		|| (a->target_node = target);
		a = a->next;
	}
}

void	find_cost(t_ps *a, t_ps *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		(!(a->median)) && (a->cost = len_a - (a->index));
		((a->target_node->median) && (a->cost += a->target_node->index))
		|| (a->cost += len_b - (a->target_node->index));
		a = a->next;
	}
}

void	find_cheapest(t_ps *a)
{
	long	cheapest;
	t_ps	*cheapest_node;

	if (!a)
		return ;
	cheapest = LONG_MAX;
	while (a)
	{
		(a->cost < cheapest) && (cheapest = a->cost, cheapest_node = a);
		a = a->next;
	}
	cheapest_node->cheapest = true;
}
