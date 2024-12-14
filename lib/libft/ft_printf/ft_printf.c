/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:00:49 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/23 00:34:26 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdarg.h>

static int	print_arg_with_format(
	t_format_specifier *format_specifier,
	va_list args
)
{
	if (format_specifier->specifier == 'c')
		return (print_character_format(args));
	if (format_specifier->specifier == 's')
		return (print_string_format(args));
	if (format_specifier->specifier == 'p')
		return (print_pointer_format(args));
	if (format_specifier->specifier == 'd' || \
		format_specifier->specifier == 'i')
		return (print_nbr_format(args));
	if (format_specifier->specifier == 'u')
		return (print_unsigned_format(args));
	if (format_specifier->specifier == 'x')
		return (print_lowercase_hex_format(args));
	if (format_specifier->specifier == 'X')
		return (print_uppercase_hex_format(args));
	if (format_specifier->specifier == '%')
		return (print_char('%'));
	return (-1);
}

int	print_arg(va_list args, const char *c, int *index)
{
	t_format_specifier	*format_specifier;
	int					arg_print_status;

	format_specifier = get_format_specifier(c);
	if (format_specifier == NULL)
		return (-1);
	*index += format_specifier->length;
	arg_print_status = print_arg_with_format(format_specifier, args);
	free(format_specifier->str);
	free(format_specifier);
	if (arg_print_status == -1)
		return (-1);
	return (arg_print_status);
}

// Start looping through the string
// Whenever encounter a '%', call the function to read it
// Return an object with the read format DATA, or just
// -1 if it failed to read the format
// Pass the format into a print function to print out the data in the format
// Move the index forward by however long the format string was
int	ft_printf(const char *format, ...)
{
	va_list				args;
	int					index;
	int					arg_print_status;
	int					printed_length;

	va_start(args, format);
	index = 0;
	printed_length = 0;
	while (format[index] != 0)
	{
		if (format[index] == '%')
		{
			arg_print_status = print_arg(args, &format[index], &index);
			if (arg_print_status == -1)
				return (-1);
			printed_length += arg_print_status;
			continue ;
		}
		arg_print_status = print_char(format[index++]);
		if (arg_print_status < 0)
			return (-1);
		printed_length += arg_print_status;
	}
	va_end(args);
	return (printed_length);
}

// Since 0 fills it all right zeroes, - cannot exist together with it
// There can only be either 0 or -

// The . can exist together with either 0 or -
// After the . is the accuracy of a number,
// or the maximum number of chararacters printed from the string
