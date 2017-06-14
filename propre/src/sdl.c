/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:56:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/06 13:39:41 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_sdl(t_env *env)
{
	if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
		ft_error_sdl();
	if ((env->sdl.win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
		ft_error_sdl();
	if ((env->sdl.rend = SDL_CreateRenderer(env->sdl.win, -1, 0)) == NULL)
		ft_error_sdl();
	env->sdl.format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	SDL_SetRenderDrawColor(env->sdl.rend, 255, 255, 255, 255);
	SDL_RenderClear(env->sdl.rend);
	env->sdl.keep = 1;
}
