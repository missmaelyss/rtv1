/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:47:45 by gauffret          #+#    #+#             */
/*   Updated: 2017/07/26 14:46:30 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color	dup_color(t_color src)
{
	t_color	dest;

	dest.red = src.red;
	dest.green = src.green;
	dest.blue = src.blue;
	dest.w = src.w;
	return (dest);
}

t_vect	dup_vect(t_vect src)
{
	t_vect	dest;

	dest.x = src.x;
	dest.y = src.y;
	dest.z = src.z;
	dest.h = src.h;
	return (dest);
}

t_calc	dup_calc(t_calc src)
{
	t_calc	dest;

	dest.color = src.color;
	dest.a = src.a;
	dest.b = src.b;
	dest.c = src.c;
	dest.solution = src.solution;
	dest.delta = src.delta;
	dest.delta_p = dup_vect(src.delta_p);
	return (dest);
}

t_cam	dup_cam(t_cam src)
{
	t_cam	cam;

	cam.pos = dup_vect(src.pos);
	cam.dir = dup_vect(src.dir);
	cam.pixel = dup_vect(src.pixel);
	cam.view_plane = dup_vect(src.view_plane);
	cam.up = dup_vect(src.up);
	cam.right = dup_vect(src.right);
	return (cam);
}

t_env	*dup_struct(t_env *src, int id)
{
	t_env	*dest;

	if (!(dest = (t_env *)malloc(sizeof(t_env))))
		ft_error();
	dest->sdl.format = src->sdl.format;
	dest->sdl.pixels = src->sdl.pixels;
	dest->thread.id = id;
	dest->cam = dup_cam(src->cam);
	dest->tmp = dup_tmp(src->tmp);
	dest->calc = dup_calc(src->calc);
	dest->obj = NULL;
	dest->obj = dup_obj(src->obj, src);
	dest->light = NULL;
	dest->light = dup_light(src->light);
	return (dest);
}
