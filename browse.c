/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 14:53:33 by marnaud          ###   ########.fr       */
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
	void (*ft_calc[env->parse.obj](*t_env));

	t_calc[0] = ft_calc_sphere;
	t_calc[1] = ft_calc_plan;
	t_calc[2] = ft_calc_cyl;
	t_calc[3] = ft_calc_cone;
	while (env->obj)
	{
		env->calc.solution = -1;
		ft_calc[env->obj.type - 1](env);
		if (env->calc.solution != -1 && (env->tmp->current ==  NULL
			|| env->calc.solution < env->tmp.solution))
		{
			env->tmp->current = env->obj;
			env->tmp.solution = env->calc.solution;
		}
		env->obj = env->obj->next;
	}
}
