/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 03:37:33 by ychbily           #+#    #+#             */
/*   Updated: 2024/05/18 21:33:21 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	free_stack2(t_ps **a, t_ps **b)
{
	(*a) && (free_stack(a), 0);
	(*b) && (free_stack(b), 0);
	write(1, "Error\n", 6);
	exit (0);
}

void	checker(t_ps **a, t_ps **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else
		free_stack2(a, b);
}

int	main(int ac, char **av)
{
	t_ps	*a;
	t_ps	*b;
	char	*line;
	char	*str;
	char	**splitted;

	if (ac < 2)
		exit(1);
	str = handle_args(av, ac);
	splitted = ft_split(str, ' ');
	stack_init(&a, splitted);
	line = get_next_line(0);
	while (line)
	{
		checker(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sort(a) == true && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
