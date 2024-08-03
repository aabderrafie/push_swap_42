/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:29:20 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/08 19:58:41 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printx(size_t i, char c)
{
	size_t	len;

	len = 0;
	if (i >= 16)
	{
		len += ft_printx(i / 16, c);
		len += ft_printx(i % 16, c);
	}
	else
	{
		if (i < 10)
			ft_printchar(i + '0');
		else if (c == 'X')
			ft_printchar(i - 10 + 'A');
		else
			ft_printchar(i - 10 + 'a');
		len++;
	}
	return (len);
}
