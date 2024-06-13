/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:42:45 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 21:50:36 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps	*find_last(t_ps **b)
{
	t_ps	*a;

	if (!b || !*b)
		return (NULL);
	a = *b;
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

static void	add_node(t_ps **a, int nbr)
{
	t_ps	*node;
	t_ps	*last_node;

	if (!a)
		return ;
	node = malloc(sizeof(t_ps));
	if (!node)
		return ;
	node->value = nbr;
	node->next = NULL;
	if (!*a)
	{
		*a = node;
		node->prev = NULL;
		return ;
	}
	last_node = *a;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = node;
	node->prev = last_node;
}

static int	repetition(t_ps *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	syntax_checker(char *str)
{
	if ((*str == '+' || *str == '-'))
		str++;
	if (!*str)
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

void	stack_init(t_ps **a, char **str)
{
	long	nbr;
	int		i;

	i = 0;
	while (str[i])
	{
		if (syntax_checker(str[i]))
			free_error(a);
		nbr = ft_atoi(str[i]);
		if (nbr == 0 && (str[i][0] != '0' || str[i][1])
			&& !((str[i][0] == '+' || str[i][0] == '-') && str[i][1] == '0'))
			free_error(a);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a);
		if (repetition(*a, (int)nbr))
			free_error(a);
		add_node(a, (int)nbr);
		i++;
	}
}
