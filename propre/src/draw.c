/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:29:34 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 18:39:37 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_display(t_env *env)
{
	SDL_SetRenderDrawColor(env->sdl.rend, 255, 255, 255, 255);
	SDL_RenderClear(env->sdl.rend);
	ft_thread(env);
	SDL_RenderCopy(env->sdl.rend, env->sdl.draw, NULL, NULL);
	SDL_RenderPresent(env->sdl.rend);
}
