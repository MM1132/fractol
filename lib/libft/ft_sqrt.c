/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:30:37 by rreimann          #+#    #+#             */
/*   Updated: 2024/11/27 13:00:36 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	abs(int nr)
{
	if (nr < 0)
		return (nr * -1);
	return (nr);
}

static int	distance(int n1, int n2)
{
	return (abs(n1 - n2));
}

int	ft_sqrt(int nb)
{
	int	number;
	int	answer;
	int	second_answer;

	if (nb == 1)
		return (1);
	if (nb < 1)
		return (0);
	number = 1;
	while (number <= 46340)
	{
		answer = number * number;
		if (answer >= nb)
		{
			second_answer = (number - 1) * (number - 1);
			if (distance(answer, nb) < distance(second_answer, nb))
				return (number);
			return (number - 1);
		}
		number++;
	}
	return (0);
}
