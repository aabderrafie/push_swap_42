/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plus_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:00:24 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/08 19:43:43 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_plus_format(const char *format, int *i, int *width)
{
	(*i)++;
	while (format[*i] == '+' || format[*i] == ' ')
		(*i)++;
	while (ft_isdigit(format[*i]))
	{
		*width = *width * 10 + (format[*i] - '0');
		(*i)++;
	}
	return (*width);
}

static int	handle_width_and_spaces(int width, int num, int num_len, int *len)
{
	if (width > num_len)
	{
		if (num > 0)
			num_len++;
		*len += print_spaces(width, num_len);
	}
	return (*len);
}

int	handle_plus_flag(const char *format, va_list args, int *i)
{
	int	num;
	int	len;
	int	width;
	int	num_len;

	len = 0;
	width = 0;
	num_len = 0;
	parse_plus_format(format, i, &width);
	if (format[*i] == 'd' || format[*i] == 'i')
	{
		num = va_arg(args, int);
		num_len = ft_numlen(num);
		handle_width_and_spaces(width, num, num_len, &len);
		if (num >= 0)
		{
			ft_printchar('+');
			len++;
		}
		len += ft_printint(num);
	}
	return (len);
}
