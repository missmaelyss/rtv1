/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:56:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 11:46:57 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_sdl(t_env *env)
{
	if ((SDL_Init(SDL_INIT_VIDEO) || TTF_Init()) != 0)
		ft_error_sdl();
	if ((env->sdl.win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, (WIDTHR + WIDTHS), HEIGHT, \
			SDL_WINDOW_SHOWN)) == NULL)
		ft_error_sdl();
	if ((env->sdl.rend = SDL_CreateRenderer(env->sdl.win, -1, 0)) == NULL)
		ft_error_sdl();
	env->sdl.format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 50)) == NULL)
		ft_error_sdl();
	env->sdl.keep = 1;
}

SDL_Texture	*ft_img_to_tex(t_env *env, char *path)
{
	SDL_Texture	*tex;
	SDL_Surface	*img;

	if ((img = SDL_LoadBMP(path)) == NULL)
		ft_error_sdl();
	if ((tex = SDL_CreateTextureFromSurface(env->sdl.rend, \
			img)) == NULL)
		ft_error_sdl();
	SDL_FreeSurface(img);
	return (tex);
}
