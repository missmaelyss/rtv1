/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/20 11:32:14 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_browse_list(t_env *env, t_vect ray_dir, t_vect ray_pos)
{
	void	(*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);
	t_obj	*lst;
	int		i;

	i = 0;
	env->tmp.i = 0;
	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	lst = env->obj;
	while (env->obj)
	{
		env->calc.solution = -1;
		ft_calc[env->obj->type - 1](env, ray_dir, ray_pos);
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
