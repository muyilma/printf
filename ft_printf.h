/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:14:46 by musyilma          #+#    #+#             */
/*   Updated: 2024/11/20 16:37:02 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_putstr(char *str);
int	ft_putnbru(unsigned int n);
int	convert_hex(unsigned int n);
int	convert_hexb(unsigned int n);
int	convert_pointer(unsigned long n);
int	ft_printf(const char *format, ...);

#endif