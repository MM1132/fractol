/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:02:19 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/27 16:20:31 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>

typedef struct s_format_specifier
{
	char	*str;
	int		length;
	char	specifier;
}	t_format_specifier;

typedef struct s_option
{
	int		length;
	char	type;
	int		is_left_aligned;
	int		with_zeroes;
	int		precision;
	int		with_space;
	int		with_sign;
	int		field_width;
}			t_option;

t_format_specifier	*get_format_specifier(const char *s);
int					ft_printf(const char *format, ...);
int					print_character_format(va_list args);
int					print_string_format(va_list args);
int					print_char(char c);
int					print_str(char *str);
int					print_pointer_format(va_list args);
int					put_int(int n);
int					print_nbr_format(va_list args);
int					print_unsigned_format(va_list args);
int					put_unsigned_int(unsigned int n);
int					put_nbr_base(unsigned long n, const char *base);
int					put_lowercase_hex(unsigned long n);
int					put_uppercase_hex(unsigned long n);
int					print_lowercase_hex_format(va_list args);
int					print_uppercase_hex_format(va_list args);

#endif
