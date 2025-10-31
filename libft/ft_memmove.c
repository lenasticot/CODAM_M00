/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:48:48 by leodum            #+#    #+#             */
/*   Updated: 2025/10/25 18:02:13 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*tempsrc;
	unsigned char		*tempdest;

	i = 0;
	tempsrc = (const unsigned char *)src;
	tempdest = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (tempdest > tempsrc)
	{
		while (n-- > 0)
			tempdest[n] = tempsrc[n];
	}
	else
	{
		while (i < n)
		{
			tempdest[i] = tempsrc[i];
			i++;
		}
	}
	return (dest);
}
