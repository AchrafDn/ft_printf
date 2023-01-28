/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:03:35 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/09 15:17:06 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_base(size_t n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_putnbr_base(n / 16);
		len += ft_putnbr_base(n % 16);
	}
	else
		len += write(1, &base[n % 16], 1);
	return (len);
}
