/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:27:33 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 14:43:27 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_event_cam_dub(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_w)
	{
		env->cam.pos.y += env->cam.inc;
		SDL_DestroyTexture(env->sdl.draw);
		ft_browse_pixels(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_SPACE)
	{
		env->cam.pos.z += env->cam.inc;
		SDL_DestroyTexture(env->sdl.draw);
		ft_browse_pixels(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_LCTRL)
	{
		env->cam.pos.z -= env->cam.inc;
		SDL_DestroyTexture(env->sdl.draw);
		ft_browse_pixels(env);
	}
}

void		ft_event_cam_rlf(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_KP_PLUS)
		env->cam.inc += 2;
	if (env->sdl.event.key.keysym.sym == SDLK_KP_MINUS)
		env->cam.inc -= 2;
	if (env->sdl.event.key.keysym.sym == SDLK_KP_MINUS)
		env->cam.inc = (env->cam.inc < 10) ? 10 : env->cam.inc;
	if (env->sdl.event.key.keysym.sym == SDLK_d)
	{
		env->cam.pos.x += env->cam.inc;
		SDL_DestroyTexture(env->sdl.draw);
		ft_browse_pixels(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_a)
	{
		env->cam.pos.x -= env->cam.inc;
		SDL_DestroyTexture(env->sdl.draw);
		ft_browse_pixels(env);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_s)
	{
		env->cam.pos.y -= env->cam.inc;
		SDL_DestroyTexture(env->sdl.draw);
		ft_browse_pixels(env);
	}
	ft_event_cam_dub(env);
}
