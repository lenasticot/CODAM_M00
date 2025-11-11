/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:51:59 by leodum            #+#    #+#             */
/*   Updated: 2025/11/09 14:51:59 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_upper(unsigned int c)
{
	char	*result;
	int		i;
	int		temp;

	i = count_hex_digits(c);
	result = malloc(sizeof(char) * i + 1);
	result[i] = '\0';
	temp = 0;
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		result[--i] = temp;
		c = c / 16;
	}
	return (result);
}
