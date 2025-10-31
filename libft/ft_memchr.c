/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:07:46 by leodum            #+#    #+#             */
/*   Updated: 2025/10/25 18:53:22 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	uc;

	tmp = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n != 0)
	{
		if (*tmp == uc)
			return ((void *)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
