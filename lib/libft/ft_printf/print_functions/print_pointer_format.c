/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:50:15 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/22 20:48:35 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_pointer_format(va_list args)
{
	unsigned long	pointer;
	int				print_counter;
	int				status;

	print_counter = 0;
	pointer = (unsigned long)va_arg(args, unsigned long);
	status = print_str("0x");
	if (status < 0)
		return (-1);
	print_counter += status;
	status = put_lowercase_hex(pointer);
	if (status < 0)
		return (-1);
	print_counter += status;
	return (print_counter);
}
