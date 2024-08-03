/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hash_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:59:58 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/08 20:01:30 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_hash_format(const char *format, int *i, int *width)
{
	(*i)++;
	while (format[*i] == ' ')
		(*i)++;
	while (ft_isdigit(format[*i]))
	{
		*width = *width * 10 + (format[*i] - '0');
		(*i)++;
	}
	return (*width);
}

static int	handle_width_and_spaces_hash(int width, unsigned int num1, int *len,
		int *num_len)
{
	if (width > *num_len)
		*len += print_spaces(width, *num_len);
	if (num1 != 0)
	{
		*len += 2;
		*num_len += 2;
	}
	return (*len);
}

int	handle_hash_flag(const char *format, va_list args, int *i)
{
	unsigned int	num1;
	int				len;
	int				width;
	int				num_len;

	len = 0;
	width = 0;
	parse_hash_format(format, i, &width);
	if (format[*i] == 'x' || format[*i] == 'X')
	{
		num1 = va_arg(args, unsigned int);
		num_len = ft_numlen(num1);
		handle_width_and_spaces_hash(width, num1, &len, &num_len);
		if (num1 != 0)
		{
			if (format[*i] == 'X')
				ft_printstr("0X");
			else
				ft_printstr("0x");
		}
		len += ft_printx(num1, format[*i]);
	}
	return (len);
}
