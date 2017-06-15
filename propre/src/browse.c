/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 18:38:55 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

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
