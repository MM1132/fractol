/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:14:00 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/22 00:14:19 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_zoom(t_fractol_data *fd)
{
	if (fd->keys.plus)
		zoom_in(fd);
	else if (fd->keys.minus)
		zoom_out(fd);
}
