/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:29:36 by leodum            #+#    #+#             */
/*   Updated: 2025/10/25 18:57:18 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	fulllength;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	fulllength = i + j;
	if (size <= i)
		return (size + j);
	if (j <= (size - i - 1))
		ft_memcpy(dst + i, src, j + 1);
	else
	{
		ft_memcpy(dst + i, src, size - i - 1);
		dst[size - 1] = '\0';
	}
	return (fulllength);
}
