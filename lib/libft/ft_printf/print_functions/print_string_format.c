/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:23 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/23 00:03:33 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	print_string_format(va_list args)
{
	char	*str;
	int		print_length;

	str = (char *)va_arg(args, char *);
	if (str == NULL)
		print_length = print_str("(null)");
	else
		print_length = print_str(str);
	if (print_length < 0)
		return (-1);
	return (print_length);
}
