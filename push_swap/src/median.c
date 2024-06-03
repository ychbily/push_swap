/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:42:27 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 15:51:11 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*convert_lst_to_arr(t_ps *a)
{
	int	index;
	int	*array;

	index = 0;
	array = malloc(sizeof(int) * stack_len(a));
	if (!array)
		return (NULL);
	while (a)
	{
		array[index++] = a->value;
		a = a->next;
	}
	return (array);
}

static void	swap_array(int *array_index1, int *array_index2)
{
	int	tmp;

	tmp = *array_index1;
	*array_index1 = *array_index2;
	*array_index2 = tmp;
}

static void	sort_array(int *array, int stack_len)
{
	int	i;
	int	j;

	j = 0;
	while (j < stack_len)
	{
		i = 0;
		while (i++ + 1 < stack_len - 1 - j)
		{
			if (array[i + 1] && array[i] > array[i + 1] && array[i + 1] != '\0')
				swap_array(&array[i], &array[i + 1]);
		}
		j++;
	}
}

int	find_median(t_ps *a)
{
	int	*array;
	int	median;
	int	median_index;

	array = convert_lst_to_arr(a);
	if (!array)
		return (-1);
	sort_array(array, stack_len(a));
	median_index = (int)(stack_len(a) / 2);
	median = array[median_index];
	free(array);
	return (median);
}
