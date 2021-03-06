/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:59:31 by yironmak          #+#    #+#             */
/*   Updated: 2022/04/19 12:09:11 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\f' || \
	c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	ans;
	int	i;
	int	sign;

	ans = 0;
	i = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ans *= 10;
		ans += str[i] - 48;
		i++;
	}
	return (sign * ans);
}

int	get_ts(t_philo *philo)
{
	struct timeval	tmp;

	gettimeofday(&tmp, &(philo->tz));
	return ((tmp.tv_sec - philo->tv_start.tv_sec) * 1000 + \
	(tmp.tv_usec - philo->tv_start.tv_usec) / 1000);
}
