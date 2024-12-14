/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:26:28 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/22 20:31:34 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	print_unsigned_format(va_list args)
{
	unsigned int	n;

	n = (unsigned int)va_arg(args, unsigned int);
	return (put_unsigned_int(n));
}
