/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:37:10 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/09 15:09:43 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_hex(unsigned int n, char str)
{
	char	*base;
	int		len;

	len = 0;
	if (str == 'x')
		base = "0123456789abcdef";
	else if (str == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_hex(n / 16, str);
		len += ft_hex(n % 16, str);
	}
	else
		len += write(1, &base[n], 1);
	return (len);
}
