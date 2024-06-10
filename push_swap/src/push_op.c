/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:32:10 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 21:50:02 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_ps **dest, t_ps **src)
{
	t_ps	*node_to_push;

	if (!(*src) || src == NULL)
		return ;
	node_to_push = (*src);
	(*src) = (*src)->next;
	if (*dest)
	{
		node_to_push->next = *dest;
		node_to_push->prev = NULL;
		(*dest)->prev = node_to_push;
	}
	else
		node_to_push->next = NULL;
	(*dest) = node_to_push;
}

void	pa(t_ps **a, t_ps **b, int flag)
{
	(flag == 1) && (write(1, "pa\n", 3));
	push(a, b);
}

void	pb(t_ps **b, t_ps **a, int flag)
{
	(flag == 1) && (write(1, "pb\n", 3));
	push(b, a);
}
