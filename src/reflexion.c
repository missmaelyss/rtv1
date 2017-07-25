/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:28:59 by marnaud           #+#    #+#             */
/*   Updated: 2017/07/25 21:36:17 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_new_color(t_env *env, int refle_lvl)
{
	double	i;
	t_color	color;

	if (env->tmp.solution > 0)
	{
		color = ft_chose_color(env);
	i = (env->tmp.solution < 1) ? 1 : (1 / env->tmp.solution);
	env->tmp.color.red = (env->tmp.color.red * (1.01 - refle_lvl)\
		+ color.red * i) / (1.01 - refle_lvl + i);
	env->tmp.color.green = (env->tmp.color.green * (1.01 - refle_lvl)\
		+ color.green * i) / (1.01 - refle_lvl + i);
	env->tmp.color.blue = (env->tmp.color.blue * (1.01 - refle_lvl)\
		+ color.blue * i) / (1.01 - refle_lvl + i);
	}
}

void		ft_reflexion(t_env *env)
{
	env->tmp.refle_lvl = env->tmp.current->refle;
	env->cam.pos = ft_calc_sol(env);
	ft_normal_vect(env);
	if (env->tmp.nb_refle < 1 && env->tmp.solution > 0)
	{
		if (env->tmp.nb_refle > 0)
		{
			env->cam.pos = ft_calc_sol(env);
			ft_normal_vect(env);
			env->cam.pixel = ft_vect_op(env->cam.pixel, '-',\
			ft_vect_op2(2 * ft_scalar(env->light->normal_vect,\
			env->cam.pixel), '*', env->light->normal_vect));
		}
		env->tmp.solution = 0;
		ft_browse_list(env, env->cam.pixel, env->cam.pos);
		(env->tmp.nb_refle)++;
	}
	ft_new_color(env, env->tmp.refle_lvl / 100);
}
