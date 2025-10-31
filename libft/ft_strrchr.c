/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:06:59 by leodum            #+#    #+#             */
/*   Updated: 2025/10/25 18:10:19 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	size_t			char_length;
	unsigned char	uc;

	uc = (unsigned char)c;
	char_length = ft_strlen(s);
	i = char_length;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
