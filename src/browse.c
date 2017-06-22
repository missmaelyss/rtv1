/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:03 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/22 14:44:07 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_browse_list(t_env *env)
{
	void	(*ft_calc[4])(t_env*);
	t_obj	*lst;
	int		i;
	int		n;

	i = 0;
	n = 0;
	env->tmp.i = 0;
	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	lst = env->obj;
	env->calc.solution = -1;
	while (env->obj)
	{
		ft_calc[env->obj->type - 1](env);
		if (env->calc.solution > 0.001  && (n ==  0
					|| env->calc.solution < env->tmp.solution))
		{
			env->tmp.current = env->obj;
			env->tmp.solution = env->calc.solution;
			env->tmp.i = i;
			n++;
		}
		env->calc.solution = -1;
		env->obj = env->obj->next;
		i++;
	}
	env->obj = lst;
}
