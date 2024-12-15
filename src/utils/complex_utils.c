/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:43:05 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 23:55:45 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	add_to_complex(t_complex *a, t_complex *b)
{
	a->re += b->re;
	a->im += b->im;
}

t_complex	*square_complex(t_complex *c)
{
	t_complex	*squared_complex;

	squared_complex = malloc(sizeof(t_complex));
	if (squared_complex == NULL)
		return (NULL);
	squared_complex->im = 0;
	squared_complex->re = 0;
	squared_complex->re += c->re * c->re;
	squared_complex->im += c->im * c->re * 2;
	squared_complex->re -= c->im * c->im;
	return (squared_complex);
}
