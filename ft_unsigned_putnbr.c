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

#include "libftprintf.h"

void	ft_unsigned_putnbr(unsigned int n)
{
	if (n <= 9)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_unsigned_putnbr (n / 10);
	ft_unsigned_putnbr (n % 10);
}
