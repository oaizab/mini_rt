/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:36:45 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/07 13:18:09 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "shape.h"

t_color	color_at_checker(t_pattern *pattern, t_shape *shape, t_tuple point)
{
	t_tuple		object_point;
	t_uv		uv;
	int			x;
	int			y;
	t_matrix	inv;

	inv = shape_inverse_transform(shape);
	object_point = matrix_mult_tuple(&inv, point);
	uv = pattern->uv_at(object_point);
	x = floor(uv.u * pattern->width);
	y = floor(uv.v * pattern->height);
	if ((x + y) % 2 == 0)
	{
		return (pattern->primary);
	}
	else
	{
		return (pattern->secondary);
	}
}

t_color	color_at_texture(t_pattern *pattern, t_shape *shape, t_tuple point)
{
	t_tuple		object_point;
	t_uv		uv;
	uint16_t	x;
	uint16_t	y;
	t_matrix	inv;

	inv = shape_inverse_transform(shape);
	object_point = matrix_mult_tuple(&inv, point);
	uv = pattern->uv_at(object_point);
	uv.v = 1 - uv.v;
	x = roundf(uv.u * (pattern->canvas.width - 1));
	y = roundf(uv.v * (pattern->canvas.height - 1));
	return (pattern->canvas.data[y][x]);
}
