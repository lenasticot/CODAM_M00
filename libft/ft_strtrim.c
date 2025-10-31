/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:22:23 by leodum            #+#    #+#             */
/*   Updated: 2025/10/25 18:47:27 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		end;
	int		front;
	int		i;
	int		token;

	end = ft_strlen(s1) -1;
	front = 0;
	i = 0;
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[front]))
		front++;
	while (ft_strchr(set, s1[end]))
		end--;
	if (front > end)
		return (ft_strdup(""));
	token = (end - front) + 1;
	result = malloc((sizeof (char) * token) + 1);
	if (result == NULL)
		return (NULL);
	while (i < token)
		result[i++] = s1[front++];
	result[i] = '\0';
	return (result);
}
