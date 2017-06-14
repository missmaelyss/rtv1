/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 17:51:30 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_browse_pixels(t_env *env)
{
	Uint32		color;

	ft_init_start(env);
	env->sdl.pos.y = 0;
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < WIDTH)
		{
			ft_init_pixel(env);
			ft_browse_list(env);
			if (env->calc.solution >= 0)
			{
				color = SDL_MapRGBA(env->sdl.format, \
					env->tmp.current->color.red, env->tmp.current->color.green,\
				   	env->tmp.current->color.blue, 255);
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
																	color;
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
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
