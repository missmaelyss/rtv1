/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:31:31 by mawasche          #+#    #+#             */
/*   Updated: 2017/06/16 16:51:27 by mawasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_shadow(t_env *env)
{
	void    (*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);
	t_obj   *lst;
	int		i;

	i = 0;
	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	lst = env->obj;
	env->tmp.darkness = 1;
	while (env->obj)
	{
		env->calc.solution = -1;
		ft_calc[env->obj->type - 1](env, env->light.light_vect, env->light.solution_point);
		if (env->calc.solution > 0 && env->tmp.i != i)
		{
			printf("%d\t%d\n", env->tmp.i, i);
			env->tmp.darkness = 0.2;
			break;
		}
		i++;
		env->obj = env->obj->next;
	}
	env->obj = lst;
}
