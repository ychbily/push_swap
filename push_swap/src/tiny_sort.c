/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:40:45 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/27 11:42:10 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ps	*high_value(t_ps *head)
{
	t_ps	*highest_value;
	int		highest;

	if (!head)
		return (NULL);
	highest = INT_MIN;
	while (head)
	{
		(head->value > highest) && (highest = head-> value
		, highest_value = head);
		head = head->next;
	}
	return (highest_value);
}

void	tiny_sort(t_ps **a)
{
	t_ps	*highest_value;

	highest_value = high_value((*a));
	if ((*a) == highest_value)
		ra(a, 1);
	else if ((*a)->next == highest_value)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}
