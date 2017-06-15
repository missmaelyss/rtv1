/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:02:17 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 12:45:23 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_pixel(t_env *env)
{
	SDL_LockMutex(env->thread.mutex);
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
	SDL_UnlockMutex(env->thread.mutex);
}
