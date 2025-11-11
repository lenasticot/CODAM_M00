/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whatisthat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:18:36 by leodum            #+#    #+#             */
/*   Updated: 2025/11/11 11:25:21 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_whatisthat(char c, va_list *special)
{
	int	i;

	i = 0;
	if (whatisthis(c, '%'))
		i = ft_putchar('%');
	else if (whatisthis(c, 'c'))
		i = ft_putchar(va_arg(*special, int));
	else if (whatisthis(c, 's'))
		i = ft_putstr(va_arg(*special, char *));
	else if ((whatisthis(c, 'd')) || (whatisthis(c, 'i')))
		i = ft_putnbr(va_arg(*special, int));
	else if (whatisthis(c, 'u'))
		i = ft_unsigned_putnbr(va_arg(*special, unsigned int));
	else if (whatisthis(c, 'x'))
		i = ft_putstr(ft_hexa_lower(va_arg(*special, unsigned int)));
	else if (whatisthis(c, 'X'))
		i = ft_putstr(ft_hexa_upper(va_arg(*special, unsigned int)));
	else if (whatisthis(c, 'p'))
		i = ft_putstr(ft_pointer(va_arg(*special, void *)));
	return (i);
}
