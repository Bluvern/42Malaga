/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manualva <manualva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:04:51 by manualva          #+#    #+#             */
/*   Updated: 2024/05/10 12:52:56 by manualva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int	ft_print_char(int ch);
int	ft_printf(char const *str, ...);
int	ft_print_string(char *str);
int	ft_print_pointer(unsigned long long ptr);
int	ft_print_number(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexa(unsigned int n, const char letter);

#endif