/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:07:03 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:42:08 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_ps **head)
{
	int	tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	sa(t_ps **a, int flag)
{
	(flag == 1) && (write(1, "sa\n", 3));
	swap(a);
}

void	sb(t_ps **b, int flag)
{
	(flag == 1) && (write(1, "sb\n", 3));
	swap(b);
}

void	ss(t_ps **a, t_ps **b, int flag)
{
	(flag == 1) && (write(1, "ss\n", 3));
	sa(a, flag);
	sb(b, flag);
}
