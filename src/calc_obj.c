/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:01:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/21 18:20:16 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_calc_sphere(t_env *env)
{
	env->calc.a = pow(env->tmp.ray_dir.x, 2) + pow(env->tmp.ray_dir.y, 2) + \
				  pow(env->tmp.ray_dir.z, 2);
	env->calc.b = 2 * (env->tmp.ray_dir.x * (env->tmp.ray_pos.x - env->obj->pos.x) + \
		env->tmp.ray_dir.y * (env->tmp.ray_pos.y - env->obj->pos.y) + \
		env->tmp.ray_dir.z * (env->tmp.ray_pos.z - env->obj->pos.z));
	env->calc.c = (pow(env->tmp.ray_pos.x - env->obj->pos.x, 2) + \
		pow(env->tmp.ray_pos.y - env->obj->pos.y, 2) + pow(env->tmp.ray_pos.z - \
		env->obj->pos.z, 2)) - pow(env->obj->radius, 2);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
			(2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
			(2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
			(2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
			(2 * env->calc.a);
}

void	ft_calc_plane(t_env *env)
{
	env->calc.solution = -((env->obj->dir.x * (env->tmp.ray_pos.x - 1) + env->obj->dir.y * \
		(env->tmp.ray_pos.y - 1) + env->obj->dir.z * (env->tmp.ray_pos.z - (-1)) + env->obj->angles.h) / \
		(env->obj->dir.x * env->tmp.ray_dir.x + env->obj->dir.y * env->tmp.ray_dir.y + env->obj->dir.z * \
		 env->tmp.ray_dir.z));
}

void	ft_calc_cone(t_env *env)
{
	env->calc.delta_p = ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos);
	env->calc.a = pow(cos(env->obj->angle * M_PI / 180), 2) * \
		ft_scalar(ft_vect_op(env->tmp.ray_dir, '-', \
		ft_vect_op2(ft_scalar(env->tmp.ray_dir, env->obj->dir), '*', \
		env->obj->dir)), ft_vect_op(env->tmp.ray_dir, '-', \
		ft_vect_op2(ft_scalar(env->tmp.ray_dir, env->obj->dir), '*', \
		env->obj->dir))) - pow(sin(env->obj->angle * M_PI / 180), 2) * \
		pow(ft_scalar(env->tmp.ray_dir, env->obj->dir), 2);
	env->calc.b = 2 * pow(cos(env->obj->angle * M_PI / 180), 2) * \
		ft_scalar(ft_vect_op(env->tmp.ray_dir, '-', \
		ft_vect_op2(ft_scalar(env->tmp.ray_dir, env->obj->dir), '*', \
		env->obj->dir)), ft_vect_op(env->calc.delta_p, '-', \
		ft_vect_op2(ft_scalar(env->calc.delta_p, env->obj->dir), '*', \
		env->obj->dir))) - 2 * pow(sin(env->obj->angle * M_PI / 180), 2) * \
		ft_scalar(env->tmp.ray_dir, env->obj->dir) * ft_scalar(env->calc.delta_p, \
		env->obj->dir);
	env->calc.c = pow(cos(env->obj->angle * M_PI / 180), 2) * \
		ft_scalar(ft_vect_op(env->calc.delta_p, '-', \
		ft_vect_op2(ft_scalar(env->calc.delta_p, env->obj->dir), '*', \
		env->obj->dir)), ft_vect_op(env->calc.delta_p, '-', \
		ft_vect_op2(ft_scalar(env->calc.delta_p, env->obj->dir), '*', \
		env->obj->dir))) - pow(sin(env->obj->angle * M_PI / 180), 2) * \
		pow(ft_scalar(env->calc.delta_p, env->obj->dir), 2);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
	{
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
		(2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
		(2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
		(2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
		(2 * env->calc.a);
	}
}

void	ft_calc_cyl(t_env *env)
{
	env->calc.delta_p = ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos);
	env->calc.a = ft_scalar(env->tmp.ray_dir, env->tmp.ray_dir) - \
		pow(ft_scalar(env->tmp.ray_dir, env->obj->dir), 2);
	env->calc.b = 2 * (ft_scalar(env->tmp.ray_dir, ft_vect_op(env->tmp.ray_pos,'-' \
	, env->obj->pos)) - ft_scalar(env->tmp.ray_dir, env->obj->dir) * \
	ft_scalar(ft_vect_op(env->tmp.ray_pos,'-', env->obj->pos), env->obj->dir));
	env->calc.c = ft_scalar(ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos), \
	ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos)) - pow(ft_scalar(ft_vect_op \
	(env->tmp.ray_pos,'-',env->obj->pos), env->obj->dir), 2) - pow(env->obj->radius, 2);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a);
}

/*
//ellipse
void	ft_calc_cyl(t_env *env, t_vect env->tmp.ray_dir, t_vect env->tmp.ray_pos)
{
	int k;
	double a1;
	double a2;

	k = 60;
	a1 = 2 * k * ft_scalar(env->tmp.ray_dir, env->obj->dir);
	a2 = pow(env->obj->radius, 2) + 2 * k * ft_scalar(ft_vect_op(env->tmp.ray_pos, '-', \
	env->obj->pos), env->obj->dir) - k;
	env->calc.a = 4 * pow(env->obj->radius, 2) * ft_scalar(env->tmp.ray_dir, env->tmp.ray_dir) \
	- pow(a1, 2);
	env->calc.b = 2 * (4 * pow(env->obj->radius, 2) * ft_scalar(env->tmp.ray_dir, \
	ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos)) - a1 * a2);
	env->calc.c = 4 * pow(env->obj->radius, 2) * ft_scalar(ft_vect_op(env->tmp.ray_pos, '-', \
	env->obj->pos), ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos)) - pow(a2, 2);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a);
}

//parabole
void	ft_calc_cyl(t_env *env, t_vect env->tmp.ray_dir, t_vect env->tmp.ray_pos)
{
	int k;

	k = 10;
	env->calc.a = ft_scalar(env->tmp.ray_dir, env->tmp.ray_dir) - \
	pow(ft_scalar(env->tmp.ray_dir, env->obj->dir), 2);
	env->calc.b = 2 * (ft_scalar(env->tmp.ray_dir, ft_vect_op(env->tmp.ray_pos, \
	'-', env->obj->pos)) - ft_scalar(env->tmp.ray_dir, env->obj->dir) * \
	(ft_scalar(ft_vect_op(env->tmp.ray_dir, '-', env->obj->pos), env->obj->dir) + \
	 2 * k));
	env->calc.c = ft_scalar(ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos), \
	ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos)) - \
	ft_scalar(ft_vect_op(env->tmp.ray_pos, '-', env->obj->pos), env->obj->dir) * \
	(ft_scalar(ft_vect_op(env->tmp.ray_dir, '-', env->obj->pos), env->obj->dir) + \
	 4 * k);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a);
}*/
