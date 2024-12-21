/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:50:45 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/21 15:51:26 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_smallest_dimension(t_fractol_data *fd)
{
	if (fd->img->width < fd->img->height)
		return (fd->img->width);
	return (fd->img->height);
}
