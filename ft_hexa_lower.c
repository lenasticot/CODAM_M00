/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_lower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:21:48 by leodum            #+#    #+#             */
/*   Updated: 2025/11/11 11:21:48 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_lower(unsigned int c)
{
	char			*result;
	int				i;
	unsigned int	temp;

	if (c == 0)
		return (ft_strdup("0"));
	i = count_hex_digits(c);
	result = calloc(i + 1, sizeof(char) * i);
	result[i] = '\0';
	temp = 0;
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		result[--i] = temp;
		c = c / 16;
	}
	return (result);
}
