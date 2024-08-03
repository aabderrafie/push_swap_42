/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:45:38 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/11 12:06:37 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flags(const char *format, va_list args, int *i)
{
	int	len;

	len = 0;
	if (format[*i] == '#')
		len += handle_hash_flag(format, args, i);
	else if (format[*i] == '+')
		len += handle_plus_flag(format, args, i);
	else if (format[*i] == ' ')
		len += handle_space_flag(format, args, i);
	return (len);
}

static int	handle_format(const char *format, va_list args, int *i)
{
	int	len;

	len = 0;
	if (format[*i] == 'd' || format[*i] == 'i')
		len += ft_printint(va_arg(args, int));
	else if (format[*i] == 'u')
		len += ft_printuint(va_arg(args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
		len += ft_printx(va_arg(args, unsigned int), format[*i]);
	else if (format[*i] == 'p')
	{
		ft_printstr("0x");
		len += 2;
		len += ft_printx(va_arg(args, size_t), 'x');
	}
	else if (format[*i] == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format[*i] == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format[*i] == '%')
	{
		ft_printchar('%');
		len++;
	}
	return (len);
}

static int	process_format(const char *format, va_list args, int *i, int *len)
{
	if (format[*i] != '+' && format[*i] != '#' && format[*i] != ' ')
		*len += handle_format(format, args, i);
	else
	{
		*len += handle_flags(format, args, i);
	}
	return (*len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			process_format(format, args, &i, &len);
		}
		else if (format[i] != '%')
		{
			ft_printchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// ft_printf("%tttttyjfjs","hello");

// 	return (0);
// }