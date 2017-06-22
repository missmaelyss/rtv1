/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:28:59 by marnaud           #+#    #+#             */
/*   Updated: 2017/06/22 15:47:11 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_new_color(t_env *env, t_obj *tmp)
{
	double	i;

	i = (env->tmp.solution < 0) ? 2 : 1 + (env->tmp.solution / 100) * 1;
	i = 2;
	env->tmp.color.red = (tmp->color.red + env->tmp.current->color.red * i) / (1 + i);
	env->tmp.color.green = (tmp->color.green + env->tmp.current->color.green * i) / (1 + i);
	env->tmp.color.blue = (tmp->color.blue + env->tmp.current->color.blue * i) / (1 + i);
}

void	ft_reflexion(t_env *env)
{
	int		i;
	t_obj	*tmp;

	i = 0;
	tmp = env->tmp.current;
	env->tmp.ray_pos = ft_calc_sol(env);
	ft_normal_vect(env);
	env->tmp.ray_dir = env->tmp.reflexion->normal_vect;
	while (i < 2 && env->tmp.solution > 0)
	{
		if (i > 0)
		{
			env->tmp.ray_pos = ft_calc_sol(env);
			ft_normal_vect(env);
			env->tmp.ray_dir = ft_vect_op(env->tmp.ray_dir, '-', ft_vect_op2(2 * ft_scalar(\
				env->tmp.reflexion->normal_vect, env->tmp.ray_dir), '*', \
					env->tmp.reflexion->normal_vect));
			printf("%f %f %f\n",	env->tmp.reflexion->normal_vect.x, 	env->tmp.reflexion->normal_vect.y, 	env->tmp.reflexion->normal_vect.z );
		}
		env->tmp.solution = 0;
		ft_browse_list(env);
		//env->tmp.reflexion = env->tmp.current;
		i++;
	}
	ft_new_color(env, tmp);
	//env->tmp.current = tmp;
	//ft_light(env, ray_dir, ray_pos);
}
