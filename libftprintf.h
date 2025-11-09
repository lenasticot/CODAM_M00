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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
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
int		count_nbr(int a);
char	*ft_hexa(int c);
char	*ft_pointer(void *c);
int		ft_printf(const char *c, ...);
void	ft_putchar(char c);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
void	ft_unsigned_putnbr(unsigned int n);
int		whatisthis(char s, char spechar);
void	ft_putstr(char *s);
void	ft_whatisthat(char c, va_list *special);
int		main(void);

#endif