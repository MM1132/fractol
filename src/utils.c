/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:15:20 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/14 17:15:42 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	rgba_to_hex(int r, int g, int b, int a)
{
	uint32_t	result;

	result = 0x00000000;
	result += (r * 0x01000000);
	result += (g * 0x00010000);
	result += (b * 0x00000100);
	result += (a * 0x00000001);
	return (result);
}
