/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:29:26 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/08 19:58:19 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuint(unsigned int i)
{
	int	len;

	len = 0;
	if (i < 0)
		return (0);
	if (i >= 10)
	{
		len += ft_printuint(i / 10);
		len += ft_printuint(i % 10);
	}
	else
	{
		ft_printchar(i + '0');
		len++;
	}
	return (len);
}
