/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:34:54 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/03 21:49:46 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_skip(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] != '\0' ) && (str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	return (i);
}

static long	atoi_helper(const char *str, int sign, long n, long i)
{
	int	nbr;

	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = n;
		n = (n * 10) + (str[i] - '0');
		if (nbr != n / 10 && sign == 1)
			return (0);
		else if (nbr != n / 10 && sign == -1)
			return (0);
		i++;
	}
	return (n * sign);
}

long	ft_atoi(const char *str)
{
	int			i;
	long		n;
	int			sign;

	n = 0;
	sign = 1;
	i = ft_skip(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (atoi_helper(str, sign, n, i));
}
