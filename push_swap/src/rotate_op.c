/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:28:58 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 21:50:36 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_ps **head)
{
	t_ps	*node;
	t_ps	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	node = (*head);
	(*head) = (*head)->next;
	last_node = find_last(head);
	last_node->next = node;
	node->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_ps **head, int flag)
{
	(flag == 1) && (write(1, "ra\n", 3));
	rotate(head);
}

void	rb(t_ps **head, int flag)
{
	(flag == 1) && (write(1, "rb\n", 3));
	rotate(head);
}

void	rr(t_ps **head_a, t_ps **head_b, int flag)
{
	(flag == 1) && (write(1, "rr\n", 3));
	rotate(head_a);
	rotate(head_b);
}
