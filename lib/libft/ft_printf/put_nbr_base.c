/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:35:29 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/27 16:25:44 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

#define G_BASE_10 "0123456789"

int	put_nbr_base(unsigned long n, const char *base)
{
	int	print_status;
	int	print_err;
	int	base_length;

	base_length = ft_strlen(base);
	print_status = 0;
	if (n / base_length != 0)
	{
		print_err = put_nbr_base(n / base_length, base);
		if (print_err < 0)
			return (-1);
		print_status += print_err;
		print_err = print_char(base[n % base_length]);
		if (print_err < 0)
			return (-1);
		print_status += print_err;
		return (print_status);
	}
	return (print_char(base[n % base_length]));
}

int	put_unsigned_int(unsigned int n)
{
	return (put_nbr_base(n, G_BASE_10));
}

int	put_int(int n)
{
	int				print_counter;
	int				print_err;
	unsigned long	converted_number;

	print_counter = 0;
	if (n < 0)
	{
		print_err = print_char('-');
		if (print_err < 0)
			return (-1);
		print_counter += print_err;
		if (n == -2147483648)
			converted_number = 2147483648;
		else
			converted_number = (n * -1);
	}
	else
		converted_number = (unsigned long)n;
	print_err = put_nbr_base(converted_number, G_BASE_10);
	if (print_err < 0)
		return (-1);
	print_counter += print_err;
	return (print_counter);
}
