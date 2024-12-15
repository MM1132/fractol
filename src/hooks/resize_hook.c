/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:56:47 by rreimann          #+#    #+#             */
/*   Updated: 2024/12/14 17:58:56 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	resize_hook(int32_t width, int32_t height, void* fractol_data)
{
	t_fractol_data	*fd;

	fd = (t_fractol_data *)fractol_data;
	ft_printf("Size... %d;%d\n", width, height);
}
