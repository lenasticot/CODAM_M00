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

#include "libftprintf.h"

char	*ft_hexa(int c)
{
	char	*result;
	int		i;
	int		j;
	int		temp;

	i = count_nbr(c);
	j = 0;
	result = malloc(sizeof(char) * i);
	temp = 0;
	while (c != 0)
	{
		temp = c % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		result[j] = temp;
		j++;
		c = c / 16;
	}
	return (result);
}
