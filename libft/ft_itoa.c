/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:08:59 by leodum            #+#    #+#             */
/*   Updated: 2025/10/25 18:55:57 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_nbr(int a)
{
	int	i;

	i = 0;
	if (a <= 0)
		i++;
	while (a != 0)
	{
		i++;
		a = a / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			token;
	int			is_neg;
	long int	num;

	num = n;
	is_neg = (num < 0);
	token = count_nbr(num);
	result = malloc(sizeof(char) * (token + 1));
	if (result == NULL)
		return (NULL);
	result[token--] = '\0';
	if (is_neg)
	{
		num = -num;
		result[0] = '-';
	}
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[token--] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}
