/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:43:52 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:42:04 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_ps **head)
{
	t_ps	*current;
	t_ps	*last;

	if (!head || !*head)
		return ;
	last = NULL;
	current = *head;
	while (current->next)
	{
		if (current->next && !current->next->next)
			last = current;
		current = current->next;
	}
	if (!last)
		return ;
	last->next = NULL;
	current->prev = NULL;
	current->next = *head;
	*head = current;
}

void	rra(t_ps **a, int flag)
{
	(flag == 1) && (write(1, "rra\n", 4));
	reverse_rotate(a);
}

void	rrb(t_ps **b, int flag)
{
	(flag == 1) && (write(1, "rrb\n", 4));
	reverse_rotate(b);
}

void	rrr(t_ps **a, t_ps **b, int flag)
{
	(flag == 1) && (write(1, "rrr\n", 4));
	reverse_rotate(a);
	reverse_rotate(b);
}
