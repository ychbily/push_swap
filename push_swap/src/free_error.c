/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:28:37 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:41:43 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
}

void	free_stack(t_ps **a)
{
	t_ps	*tmp;
	t_ps	*curr;

	if (!a)
		return ;
	curr = *a;
	while (curr)
	{
		tmp = curr->next;
		curr->value = 0;
		free(curr);
		curr = tmp;
	}
	*a = NULL;
}

void	free_error(t_ps **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
