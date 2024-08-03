/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:44:52 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/13 12:01:07 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	calculate_number(const char *str, int sign, int *error, int i)
{
	long long	tmp;
	long long	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		if (sign == 1 && (tmp > INT_MAX / 10 || (tmp == INT_MAX / 10 && str[i]
					- '0' > INT_MAX % 10)))
		{
			*error = 1;
			return (-1);
		}
		if (sign == -1 && (tmp > -(long long)INT_MIN / 10 || (tmp
					== -(long long)INT_MIN / 10 && str[i] - '0'
					> -(long long)INT_MIN % 10)))
		{
			*error = 1;
			return (-1);
		}
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_atoi(const char *str, int *error)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (calculate_number(str + i, sign, error, 0));
}
