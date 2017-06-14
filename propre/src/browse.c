/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 16:43:28 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_browse_pixels(t_env *env)
{
	SDL_Texture *texture;
	SDL_Surface *ecran;
	SDL_Surface *pix;

	pix = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);
	ecran = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
	ft_init_start(env);
	env->sdl.pos.y = 0;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < WIDTH)
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
			ft_browse_list(env);
			if (env->calc.solution >= 0)
			{
				SDL_FillRect(pix, NULL, SDL_MapRGB(ecran->format, \
							env->tmp.current->color.red  , env->tmp.current->color.green,  env->tmp.current->color.blue));
				SDL_BlitSurface(pix, NULL, ecran, &env->sdl.pos);
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	texture = SDL_CreateTextureFromSurface(env->sdl.rend, ecran);
	SDL_RenderCopy(env->sdl.rend, texture, NULL, NULL);
	SDL_RenderPresent(env->sdl.rend);
	SDL_DestroyTexture(texture);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0 , 0, 0));
}

void	ft_browse_list(t_env *env)
{
	void	(*ft_calc[1])(t_env*);
	t_obj	*lst;

	ft_calc[0] = ft_calc_sphere;
	/*ft_calc[1] = ft_calc_plan;
	  ft_calc[2] = ft_calc_cyl;
	  ft_calc[3] = ft_calc_cone;*/
	lst = env->obj;
	while (env->obj)
	{
		env->calc.solution = -1;
		ft_calc[env->obj->type - 1](env);
		if (env->calc.solution != -1 && (env->tmp.current ==  NULL
					|| env->calc.solution < env->tmp.solution))
		{
			env->tmp.current = env->obj;
			env->tmp.solution = env->calc.solution;
		}
		env->obj = env->obj->next;
	}
	env->obj = lst;
}
