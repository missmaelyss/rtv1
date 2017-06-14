/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 13:07:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_browse_pixels(t_env *env)
{
	ft_init_start(env);
	env->sdl.pos.y = 0;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < WIDTH)
		{
			env->cam.pixel.x = env->cam.view_plane.x + env->cam.right.x * \
			XINDENT * env->sdl.pos.x - env->cam.up.x * YINDENT * sdl->pos.y;
			ft_browse_list(env);
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
}

void	ft_browse_list(t_env *env)
{
	while (env->obj)
	{
		if (env->obj->type == SPHERE)
			ft_calc_sphere(env);
		else if (env->obj->type == PLANE)
			ft_calc_plane(env);
		else if (env->obj->type == CYL)
			ft_calc_cyl(env);
		else if (env->obj->type == CONE)
			ft_calc_cone(env);
		env->obj = env->obj->next;
	}
}
