/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whatisthat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:18:36 by leodum            #+#    #+#             */
/*   Updated: 2025/11/09 15:38:33 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_whatisthat(char c, va_list *special)
{
	char	*result;

	if (whatisthis(c, '%'))
		write (1, "%", 1);
	else if (whatisthis(c, 's'))
		ft_putstr(result = va_arg(*special, char *));
	else if (whatisthis(c, 'c'))
		ft_putchar(va_arg(*special, int));
	else if ((whatisthis(c, 'd')) || (whatisthis(c, 'i')))
		ft_putnbr(va_arg(*special, int));
	else if (whatisthis(c, 'u'))
		ft_unsigned_putnbr(va_arg(*special, unsigned int));
	else if ((whatisthis(c, 'x')) || (whatisthis(c, 'X')))
		ft_putstr(result = ft_hexa(va_arg(*special, int)));
	else if (whatisthis(c, 'p'))
		ft_putstr(result = ft_pointer(va_arg(*special, void *)));
}
