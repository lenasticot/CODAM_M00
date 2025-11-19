/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodum <leodum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:57:04 by leodum            #+#    #+#             */
/*   Updated: 2025/11/09 14:57:04 by leodum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		count_hex_digits(unsigned long b);
char	*ft_hexa_upper(unsigned int c);
char	*ft_pointer(void *c);
int		ft_printf(const char *c, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_unsigned_putnbr(unsigned int n);
int		whatisthis(char s, char spechar);
int		ft_putstr(char *s);
int		ft_whatisthat(char c, va_list *special);
char	*ft_hexa_lower(unsigned int c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);

#endif