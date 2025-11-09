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

#include "libftprintf.h"

int	ft_printf(const char *c, ...)
{
	va_list	special;
	int		i;
	int		len;

	va_start(special, c);
	i = 0;
	if (c == NULL)
		return (0);
	len = ft_strlen(c) - 1;
	if ((c[i] == '%' && c[i + 1] == '\0')
		|| (c[len] == '%' && c[len - 1] != '%'))
		return (0);
	while (c[i])
	{
		if (whatisthis(c[i], '%'))
		{
			ft_whatisthat(c[i +1], &special);
			i += 2;
		}
		else
		{
			ft_putchar(c[i]);
			i++;
		}
	}
	va_end(special);
	return (i);
}

// dont forget the token question