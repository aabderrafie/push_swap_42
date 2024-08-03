/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:01:38 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/11 12:02:29 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_space_flag_int(va_list args, int withd)
{
	int	numb;
	int	numb_len;
	int	len;

	numb = va_arg(args, int);
	numb_len = ft_numlen(numb);
	len = 0;
	if (numb >= 0 && withd == 0)
		len += ft_printchar(' ');
	if (withd > numb_len)
		len += print_spaces(withd, numb_len);
	len += ft_printint(numb);
	return (len);
}

static int	handle_space_flag_str(va_list args, int withd)
{
	char	*str;
	int		len;
	int		str_len;

	str = va_arg(args, char *);
	len = 0;
	if (str == NULL)
	{
		if (withd > 6)
			len += print_spaces(withd, 6);
		write(1, "(null)", 6);
		return (len + 6);
	}
	str_len = ft_strlen(str);
	if (withd > str_len)
		len += print_spaces(withd, str_len);
	len += ft_printstr(str);
	return (len);
}

int	handle_space_flag(const char *format, va_list args, int *i)
{
	int	withd;
	int	len;

	withd = 0;
	len = 0;
	(*i)++;
	while (format[*i] == ' ' || format[*i] == '+')
	{
		if (format[*i] == '+')
			return (len + handle_plus_flag(format, args, i));
		(*i)++;
	}
	while (ft_isdigit(format[*i]))
	{
		withd = withd * 10 + (format[*i] - '0');
		(*i)++;
	}
	if (format[*i] == 'd' || format[*i] == 'i')
		len += handle_space_flag_int(args, withd);
	else if (format[*i] == 's')
		len += handle_space_flag_str(args, withd);
	return (len);
}
