/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:35:02 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/21 16:35:43 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol_data *fd)
{
	fd->camera.target_zoom *= ZOOM_FACTOR;
}

void	zoom_out(t_fractol_data *fd)
{
	fd->camera.target_zoom /= ZOOM_FACTOR;
}
