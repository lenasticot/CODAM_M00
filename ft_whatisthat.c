/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whatisthat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:18:36 by leodum            #+#    #+#             */
/*   Updated: 2025/11/19 13:18:45 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wit_free(char c, va_list **special, int i)
{
	char	*res;

	if (whatisthis(c, 'x'))
	{
		res = ft_hexa_lower(va_arg(**special, unsigned int));
		i = ft_putstr(res);
		free(res);
	}
	else if (whatisthis(c, 'X'))
	{
		res = ft_hexa_upper(va_arg(**special, unsigned int));
		i = ft_putstr(res);
		free(res);
	}
	else if (whatisthis(c, 'p'))
	{
		res = ft_pointer(va_arg(**special, void *));
		i = ft_putstr(res);
		free(res);
	}
	return (i);
}

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
	else if (whatisthis(c, 'x') || whatisthis(c, 'X') || whatisthis(c, 'p'))
		i = ft_wit_free(c, &special, i);
	return (i);
}
