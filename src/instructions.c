/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:06:36 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 23:38:05 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_instrcutions(void)
{
	ft_printf("Usage:\n");
	ft_printf("\n");
	ft_printf("For Mandlebrot: ./fractol <random argument>\n");
	ft_printf("For Julia: ./fractol <random argument> <number>\n");
	ft_printf("\n");
	ft_printf("In Julia, the <number> is between 1 and 3\n");
	ft_printf("...for selectig the different types of Julia sets\n");
	ft_printf("\n");
	ft_printf("Controls:\n");
	ft_printf("Move around => WASD\n");
	ft_printf("Increase level of detail => E\n");
	ft_printf("DE-crease level of detail => Q\n");
	ft_printf("Zoom IN-OUT by scrolling mouse\n");
	ft_printf("\n");
	ft_printf("Have fun evaluating me! :)\n");
}
