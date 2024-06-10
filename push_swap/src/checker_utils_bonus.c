/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:45:42 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/10 18:23:59 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

void	parse(int ac, char **av, t_ps **a)
{
	char	*str;
	char	**splitted;

	if (ac <= 1)
		exit(1);
	((ac == 2 && !av[1][0]))
		&& (write(2, "Error\n", 6), exit(1), 0);
	str = handle_args(av, ac);
	splitted = ft_split(str, ' ');
	stack_init(a, splitted);
	free(str);
	free_ptr(splitted);
	free(splitted);
}
