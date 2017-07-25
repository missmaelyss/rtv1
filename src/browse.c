/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 20:59:50 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static	void	ft_calc_obj(t_env *env, t_vect ray_dir, t_vect ray_pos)
{
	void	(*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);
	
	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	ft_calc[env->obj->type - 1](env, ray_dir, ray_pos);
}

void	ft_browse_list(t_env *env, t_vect ray_dir, t_vect ray_pos)
{
	t_obj	*lst;
	int		i;

	i = 0;
	env->tmp.i = 0;
	env->tmp.solution = -1;
	lst = env->obj;
	while (env->obj)
	{
		env->calc.solution = -1;
		ft_calc_obj(env, ray_dir, ray_pos);
		if (env->calc.solution > 0  && (env->tmp.current ==  NULL
					|| env->calc.solution < env->tmp.solution))
		{
			env->tmp.current = env->obj;
			env->tmp.solution = env->calc.solution;
			env->tmp.i = i;
		}
		env->obj = env->obj->next;
		i++;
	}
	env->obj = lst;
}
