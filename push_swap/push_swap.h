/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:07:20 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/02 23:01:16 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "limits.h"
# include "stdbool.h"
# include "get_next_line/get_next_line.h"

typedef struct s_ps
{
	int			value;
	int			cost;
	int			index;
	bool		median;
	bool		cheapest;
	struct s_ps	*target_node;
	struct s_ps	*next;	
	struct s_ps	*prev;		
}	t_ps;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
long	ft_atoi(const char *str);
void	free_ptr(char **ptr);
void	free_error(t_ps **a);
bool	check_sort(t_ps *a);
char	*ft_strdup(const char *s1);
void	stack_init(t_ps **a, char **str);
int		stack_len(t_ps *a);
void	sa(t_ps **head, int flag);
void	sb(t_ps **b, int flag);
void	ss(t_ps **a, t_ps **b, int flag);
void	pa(t_ps **a, t_ps **b, int flag);
void	pb(t_ps **b, t_ps **a, int flag);
void	ra(t_ps **head, int flag);
void	rb(t_ps **head, int flag);
void	rr(t_ps **head_a, t_ps **head_b, int flag);
void	rra(t_ps **a, int flag);
void	rrb(t_ps **b, int flag);
void	rrr(t_ps **a, t_ps **b, int flag);
t_ps	*find_last(t_ps **a);
void	tiny_sort(t_ps **a);
void	push_swap_algo(t_ps **a, t_ps **b);
void	print_stack(t_ps *top);
void	indexing(t_ps *a);
void	find_target(t_ps *a, t_ps *b);
void	find_cost(t_ps *a, t_ps *b);
void	find_cheapest(t_ps *b);
t_ps	*min_value(t_ps *stack);
t_ps	*max_value(t_ps *stack);
t_ps	*chpst_node(t_ps *head);
void	rotate_both(t_ps **a, t_ps **b, t_ps *cheapest_node);
void	rev_rotate_both(t_ps **a, t_ps **b, t_ps *cheapest_node);
void	checking_before_pushing(t_ps **head, t_ps *cheapest_node, char c);
void	free_stack(t_ps **a);
void	bring_min_to_top(t_ps **a);
void	finish_working(t_ps **a, t_ps **b);
void	start_working(t_ps *a, t_ps *b);
char	*handle_args(char **av, int ac);
void	tiny_sort_rev(t_ps **a);
t_ps	*high_value(t_ps *head);
int		find_median(t_ps *a);

#endif
