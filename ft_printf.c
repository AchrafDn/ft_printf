/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:00 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/09 15:29:39 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_res(const char *str, int i, va_list varg)
{
	int	rlen;

	rlen = 0;
	if (str[i + 1] == 'c')
		rlen += ft_putchar(va_arg(varg, int));
	else if (str[i + 1] == 's')
		rlen += ft_putstr(va_arg(varg, char *));
	else if (str[i + 1] == 'i' || str[i + 1] == 'd')
		rlen += ft_putnbr(va_arg(varg, int));
	else if (str[i + 1] == 'u')
		rlen += ft_putunsigned(va_arg(varg, unsigned int));
	else if (str[i + 1] == 'p')
		rlen += write(1, "0x", 2) + ft_putnbr_base(va_arg(varg, size_t));
	else if (str[i + 1] == 'X' || str[i + 1] == 'x')
		rlen += ft_hex(va_arg(varg, unsigned int), str[i + 1]);
	else if (str[i + 1] == '%')
		rlen += write(1, "%", 1);
	return (rlen);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		rlen;
	va_list	varg;

	va_start(varg, str);
	rlen = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			rlen += ft_res(str, i, varg);
			i++;
		}
		else
			rlen += ft_putchar(str[i]);
	}
	return (rlen);
}
