/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:28:59 by marnaud           #+#    #+#             */
/*   Updated: 2017/07/25 21:37:55 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_new_color(t_env *env)
{
	double	i;
	t_color	color;

	if (env->tmp.solution > 0)
	{
	color = ft_chose_color(env);
	i = (env->tmp.solution < 1) ? 1 : (1 / env->tmp.solution) *\
		(1 - env->tmp.refle_lvl / 100);
	env->tmp.color.red = (env->tmp.color.red +\
			color.red * i) / (1 + i);
	env->tmp.color.green = (env->tmp.color.green +\
			color.green * i) / (1 + i);
	env->tmp.color.blue = (env->tmp.color.blue +\
			color.blue * i) / (1 + i);
	}
}

void	ft_refraction(t_env *env)
{
	double	n1;
	double	n2;
	double	cos1;
	double	cos2;
	t_vect	ray_dir_inv;

	n1 = 1;
	n2 = 1.2;
	env->tmp.refle_lvl = env->tmp.refle_lvl;
	env->cam.pos = ft_calc_sol(env);
	ft_normal_vect(env);
	ray_dir_inv.x = -env->cam.pixel.x;
	ray_dir_inv.y = -env->cam.pixel.y;
	ray_dir_inv.z = -env->cam.pixel.z;
	cos1 = ft_scalar(env->light->normal_vect, ray_dir_inv);
	cos2 = sqrt(1 - pow(n1 / n1, 2) * (1 - pow(cos1, 2)));
	if (cos1 > 0)
		env->cam.pixel = ft_vect_op(ft_vect_op2((n1 / n2), '*', env->cam.pixel), '+',\
			ft_vect_op2((n1 / n2) * cos1 - cos2, '*', env->light->normal_vect));
	else
		env->cam.pixel = ft_vect_op(ft_vect_op2((n1 / n2), '*', env->cam.pixel), '+', \
			ft_vect_op2((n1 / n2) * cos1 + cos2, '*', env->light->normal_vect));
	env->tmp.solution = 0;
	ft_browse_list(env, env->cam.pixel, env->cam.pos);
	(env->tmp.refle_lvl)++;
	ft_new_color(env);
}
