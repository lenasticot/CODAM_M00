/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:56:48 by leodum            #+#    #+#             */
/*   Updated: 2025/11/09 14:56:48 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 9)
	{
		i += ft_putchar(n + '0');
		return (i);
	}
	i += ft_unsigned_putnbr (n / 10);
	i += ft_unsigned_putnbr (n % 10);
	return (i);
}
