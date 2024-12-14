/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:49:21 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/27 16:25:31 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define G_LOWERCASE_HEX_BASE "0123456789abcdef"
#define G_UPPERCASE_HEX_BASE "0123456789ABCDEF"

int	put_lowercase_hex(unsigned long n)
{
	return (put_nbr_base(n, G_LOWERCASE_HEX_BASE));
}

int	put_uppercase_hex(unsigned long n)
{
	return (put_nbr_base(n, G_UPPERCASE_HEX_BASE));
}
