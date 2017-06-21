/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:02:17 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 16:08:33 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_pixel(t_env *env)
{
	env->tmp.solution = -1;
	env->tmp.current = NULL;
	env->calc.solution = -1;
	env->cam.pixel.x = env->cam.view_plane.x + env->cam.right.x * \
		XINDENT * env->sdl.pos.x - env->cam.up.x * \
		YINDENT * env->sdl.pos.y;
	env->cam.pixel.y = env->cam.view_plane.y + env->cam.right.y * \
		XINDENT * env->sdl.pos.x - env->cam.up.y * \
		YINDENT * env->sdl.pos.y;
	env->cam.pixel.z = env->cam.view_plane.z + env->cam.right.z * \
		XINDENT * env->sdl.pos.x - env->cam.up.z * \
		YINDENT * env->sdl.pos.y;
}

void	ft_calc_angles(t_env *env)
{
	t_obj	*tmp;

	tmp = env->obj;
	while (env->obj)
	{
		if (env->obj->type != SPHERE)
		{
			env->obj->dir.x = 0;
			env->obj->dir.y = 0;
			env->obj->dir.z = 1;
			env->obj->dir = ft_vect_rot(env->obj->dir, env->obj->angles.z, 1);
			env->obj->dir = ft_vect_rot(env->obj->dir, env->obj->angles.y, 2);
			env->obj->dir = (env->obj->dir.x != 1 && env->obj->dir.x != -1) ? \
				ft_vect_rot(env->obj->dir, env->obj->angles.x, 3) : \
				ft_vect_rot(env->obj->dir, env->obj->angles.x, 1);
		}
		env->obj = env->obj->next;
	}
	env->obj = tmp;
}
