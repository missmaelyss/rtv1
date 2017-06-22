/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:29:34 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/21 17:49:19 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_display(t_env *env)
{
	SDL_SetRenderDrawColor(env->sdl.rend, 255, 255, 255, 255);
	SDL_RenderClear(env->sdl.rend);
	ft_browse_pixels(env);
	//ft_thread(env);
	SDL_RenderCopy(env->sdl.rend, env->sdl.draw, NULL, NULL);
	SDL_RenderPresent(env->sdl.rend);
}

Uint32	ft_chose_color(t_env *env)
{
	t_vecti	tmp;
	t_vect	sol;
	Uint32	color[2];

	color[0] = SDL_MapRGBA(env->sdl.format, env->tmp.color.red * \
				env->tmp.reflexion->power * env->tmp.reflexion->darkness, \
				env->tmp.color.\
				green * env->tmp.reflexion->power * env->tmp.reflexion->darkness, \
				env->tmp.color.blue * env->tmp.reflexion->power * \
				env->tmp.reflexion->darkness, 255);
	color[1] = SDL_MapRGBA(env->sdl.format, env->tmp.reflexion->tile.red * \
				env->tmp.reflexion->power * env->tmp.reflexion->darkness, \
				env->tmp.reflexion->tile.\
				green * env->tmp.reflexion->power * env->tmp.reflexion->darkness, \
				env->tmp.reflexion->tile.blue * env->tmp.reflexion->power * \
				env->tmp.reflexion->darkness, 255);
	if (env->tmp.current->tex == TILE)
	{
		sol = ft_calc_sol(env);
		tmp.x = (int)(floor(sol.x / env->tmp.current->tile.w));	
		tmp.y = (int)(floor(sol.y / env->tmp.current->tile.w));	
		tmp.z = (int)(floor(sol.z / env->tmp.current->tile.w));
		if (tmp.z % 2 == 0)
		{
			if ((tmp.x % 2 == 0 && tmp.y % 2 == 0) || (tmp.x % 2 != 0 && tmp.y \
					% 2 != 0))
				return (color[0]);
			else
				return (color[1]);
		}
		else
		{
			if ((tmp.x % 2 == 0 && tmp.y % 2 == 0) || (tmp.x % 2 != 0 && tmp.y \
					% 2 != 0))
				return (color[1]);
			else
				return (color[0]);
		}
	}
	else
		return (color[0]);
}
