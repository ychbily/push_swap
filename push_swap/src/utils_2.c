/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:03:06 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/26 16:34:55 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;

	ptr = str;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

t_ps	*min_value(t_ps *stack)
{
	long	min;
	t_ps	*target;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			target = stack;
		}
		stack = stack->next;
	}
	return (target);
}

t_ps	*max_value(t_ps *stack)
{
	int		max;
	t_ps	*target;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		(stack->value > max) && (max = stack->value, target = stack);
		stack = stack->next;
	}
	return (target);
}

t_ps	*chpst_node(t_ps *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}
