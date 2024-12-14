/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:29:16 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/27 16:33:11 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	output;
	long	multiplier;

	while (ft_isspace(*str))
		str++;
	multiplier = 1;
	if (*str == '-')
	{
		multiplier = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	output = 0;
	while (ft_isdigit(*str))
	{
		output *= 10;
		output += *str - 48;
		str++;
	}
	return (output * multiplier);
}

// #include <stdlib.h>
// #include <stdio.h>

// void	print_test(char *str)
// {
// 	printf("`%s` => %d : %d\n", str, ft_atoi(str), atoi(str));
// }

// int	main(void)
// {
// 	print_test("5");
// 	print_test(" 5");
// 	print_test(" 5...");
// 	print_test("    42...");
// 	print_test("	42   ");
// 	print_test("	asd555");
// 	print_test("2147483647");

// 	return (0);
// }
