/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:28:59 by marnaud           #+#    #+#             */
/*   Updated: 2017/07/27 16:29:55 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_new_color(t_env *env, int refle_lvl)
{
	t_color color;

	color.red = 0;
	color.green = 0;
	color.blue = 0;
	if (env->tmp.solution > 0)
		color = ft_chose_color(env);
	env->tmp.color.red = (env->tmp.color.red * refle_lvl\
			+ color.red * (100 - refle_lvl)) / 100;
	env->tmp.color.green = (env->tmp.color.green * refle_lvl\
			+ color.green * (100 - refle_lvl)) / 100;
	env->tmp.color.blue = (env->tmp.color.blue * refle_lvl\
			+ color.blue * (100 - refle_lvl)) / 100;
}

void		ft_reflexion(t_env *env)
{
	int		refle_lvl;

	refle_lvl = env->tmp.current->refle;
	env->tmp.ray_pos = env->light->solution_point;
	env->tmp.ray_dir = ft_vect_op(env->tmp.ray_dir, '-',\
			ft_vect_op2(2 * ft_scalar(env->light->normal_vect,\
					env->tmp.ray_dir), '*', env->light->normal_vect));
	env->tmp.solution = 0;
	ft_browse_list(env, env->tmp.ray_dir, env->tmp.ray_pos, 0);
	ft_new_color(env, 100 - 50);
}
