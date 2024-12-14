/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:39 by rreimann          #+#    #+#             */
/*   Updated: 2024/10/22 20:17:35 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// varsity
// tumultuous
int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	write_error;
	int	number_of_chars_written;

	number_of_chars_written = 0;
	while (*str != 0)
	{
		write_error = print_char(*str);
		if (write_error == -1)
			return (-1);
		number_of_chars_written++;
		str++;
	}
	return (number_of_chars_written);
}
