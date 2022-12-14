/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:13:25 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/07 17:31:50 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "color.h"
# include "canvas.h"
# include "tuple.h"

typedef struct s_uv
{
	float	u;
	float	v;
}				t_uv;

typedef struct s_shape		t_shape;
typedef struct s_pattern	t_pattern;
typedef t_color				(*t_color_at_fun)(t_pattern *, t_shape *, t_tuple);
typedef t_uv				(*t_uv_at_fun)(t_tuple);

typedef struct s_pattern
{
	t_color_at_fun	color_at;
	t_uv_at_fun		uv_at;
	uint16_t		width;
	uint16_t		height;
	t_color			primary;
	t_color			secondary;
	t_canvas		canvas;
}				t_pattern;

t_pattern	checker(uint16_t width, uint16_t height, t_color *primary,
				t_color *secondary);
t_pattern	texture(t_canvas *canvas);

t_color		color_at_checker(t_pattern *pattern, t_shape *shape, t_tuple point);
t_color		color_at_texture(t_pattern *pattern, t_shape *shape, t_tuple point);

t_uv		uv_at_sphere(t_tuple point);
t_uv		uv_at_plane_ch(t_tuple point);
t_uv		uv_at_plane_tx(t_tuple point);
t_uv		uv_at_cylinder_ch(t_tuple point);
t_uv		uv_at_cylinder_tx(t_tuple point);

#endif