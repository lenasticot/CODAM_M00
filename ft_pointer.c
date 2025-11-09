/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:53:10 by leodum            #+#    #+#             */
/*   Updated: 2025/11/09 14:53:10 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pointer(void *c)
{
	char			*result;
	int				i;
	unsigned long	temp;
	unsigned long	c_bis;

	c_bis = (unsigned long)c;
	i = count_hex_digits(c_bis) + 2;
	result = malloc((sizeof(char) * i) + 1);
	result[i--] = '\0';
	temp = 0;
	while (c_bis != 0)
	{
		temp = c_bis % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		result[i] = temp;
		i--;
		c_bis = c_bis / 16;
	}
	result[i--] = 'x';
	result[i] = '0';
	return (result);
}
