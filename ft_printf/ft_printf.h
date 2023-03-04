/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:01:57 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/01 15:29:57 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr2(unsigned int n);
int	ft_putstr(char *s);
int	ft_putnbr_base(unsigned int num, char c);
int	ft_putadrs_base(unsigned long num);
int	ft_printf(const char *format, ...);

#endif