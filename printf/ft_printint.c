/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:28:57 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/08 19:52:50 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int i)
{
	int	len;

	len = 0;
	if (i == -2147483648)
	{
		ft_printstr("-2147483648");
		return (11);
	}
	if (i < 0)
	{
		ft_printchar('-');
		len++;
		i = -i;
	}
	if (i >= 10)
	{
		len += ft_printint(i / 10);
		len += ft_printint(i % 10);
	}
	else
	{
		ft_printchar(i + '0');
		len++;
	}
	return (len);
}
