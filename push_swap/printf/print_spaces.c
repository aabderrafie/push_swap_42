/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:10:05 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/08 19:56:51 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spaces(int width, int num_spaces)
{
	int	len;

	len = 0;
	while (width-- > num_spaces)
	{
		ft_printchar(' ');
		len++;
	}
	return (len);
}
