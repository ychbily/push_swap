/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:41:45 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/07 16:27:31 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line.h"

int		ft_strcmp(const char *s1, const char *s2);
void	free_stack2(t_ps **a, t_ps **b);
void	checker(t_ps **a, t_ps **b, char *line);
void	parse(int ac, char **av, t_ps **a);

#endif