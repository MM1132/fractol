/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:13:21 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/15 23:40:09 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol_data	*fd;

	xdelta += 1;
	fd = (t_fractol_data *)param;
	if (ydelta > 0.0)
		fd->camera->zoom *= 0.4;
	else
		fd->camera->zoom /= 0.4;
	put_fractol(fd);
}
