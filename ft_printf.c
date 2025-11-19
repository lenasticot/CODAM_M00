/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:19:44 by leodum            #+#    #+#             */
/*   Updated: 2025/11/09 14:19:44 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
	va_list	special;
	int		i;
	int		token;

	va_start(special, c);
	i = 0;
	token = 0;
	while (c[i])
	{
		if (whatisthis(c[i], '%'))
		{
			token += ft_whatisthat(c[i +1], &special);
			i += 2;
		}
		else
			token += ft_putchar(c[i++]);
	}
	if (token < 0)
		return (-1);
	va_end(special);
	return (token);
}
