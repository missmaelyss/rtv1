/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/16 13:46:40 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_browse_list(t_env *env)
{
	void	(*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);
	t_obj	*lst;

	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	lst = env->obj;
	while (env->obj)
	{
		env->calc.solution = -1;
		ft_calc[env->obj->type - 1](env, env->cam.pixel, env->cam.pos);
		if (env->calc.solution > 0  && (env->tmp.current ==  NULL
					|| env->calc.solution < env->tmp.solution))
		{
			env->tmp.current = env->obj;
			env->tmp.solution = env->calc.solution;
		}
		env->obj = env->obj->next;
	}
	env->obj = lst;
}
