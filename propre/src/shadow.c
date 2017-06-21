/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:31:31 by mawasche          #+#    #+#             */
/*   Updated: 2017/06/21 11:12:30 by mawasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_shadow(t_env *env)
{
	void    (*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);
	t_obj   *lst;
	int		i;
	t_vect	solution;
	t_vect	test;
	int		power;
	t_light	*tmp;

	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	lst = env->obj;
	tmp = env->light;
	power = 0;
	env->tmp.darkness = 1;
	while (env->light)
	{
		i = 0;
		env->light->solution_point.x = env->cam.pos.x + env->cam.pixel.x *\
									  env->tmp.solution;
		env->light->solution_point.y = env->cam.pos.y + env->cam.pixel.y *\
									  env->tmp.solution;
		env->light->solution_point.z = env->cam.pos.z + env->cam.pixel.z *\
									  env->tmp.solution;
		env->light->light_vect.x = env->light->pos.x - env->light->solution_point.x;
		env->light->light_vect.y = env->light->pos.y - env->light->solution_point.y;
		env->light->light_vect.z = env->light->pos.z - env->light->solution_point.z;
		env->light->norme = sqrt(pow(env->light->light_vect.x,2) +\
				pow(env->light->light_vect.y,2) + pow(env->light->light_vect.z,2));
		test.x = env->light->light_vect.x / env->light->norme;
		test.y = env->light->light_vect.y / env->light->norme;
		test.z = env->light->light_vect.z / env->light->norme;
		env->calc.solution = -1;
		while (env->obj)
		{
			ft_calc[env->obj->type - 1](env, test,\
					env->light->solution_point);
			if (env->calc.solution > 0.001 && env->tmp.i != i)
			{
				solution.x = env->calc.solution * test.x;
				solution.y = env->calc.solution * test.y;
				solution.z = env->calc.solution * test.z;
				solution.h = sqrt(pow(solution.x,2) +\
						pow(solution.y,2) + pow(solution.z,2));
				if (solution.h < env->light->norme)
					env->tmp.darkness = 0.3;
				break;
			}
			i++;
			env->obj = env->obj->next;
		}
		power += (env->calc.solution < 0.001) ? 1 : 0;
		env->obj = lst;
		env->light = env->light->next;
	}
	env->tmp.darkness = (power < 4 && env->tmp.darkness != 1) ? env->tmp.darkness * (1 + 0.75 * power) : 1;
	env->light = tmp;
}
