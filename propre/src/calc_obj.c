/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:01:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 16:26:22 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_calc_sphere(t_env *env)
{
	env->calc.a = pow(env->cam.pixel.x, 2) + pow(env->cam.pixel.y, 2) + \
				  pow(env->cam.pixel.z, 2);
	env->calc.b = 2 * (env->cam.pixel.x * (env->cam.pos.x - env->obj->pos.x) + \
		env->cam.pixel.y * (env->cam.pos.y - env->obj->pos.y) + \
		env->cam.pixel.z * (env->cam.pos.z - env->obj->pos.z));
	env->calc.c = (pow(env->cam.pos.x - env->obj->pos.x, 2) + \
		pow(env->cam.pos.y - env->obj->pos.y, 2) + pow(env->cam.pos.z - \
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
	env->calc.solution = -((env->obj->dir.x * (env->cam.pos.x - 1) + env->obj->dir.y * \
		(env->cam.pos.y - 1) + env->obj->dir.z * (env->cam.pos.z - (-1)) + env->obj->angles.h) / \
		(env->obj->dir.x * env->cam.pixel.x + env->obj->dir.y * env->cam.pixel.y + env->obj->dir.z * \
		 env->cam.pixel.z));
}

void	ft_calc_cone(t_env *env)
{
	env->calc.a = pow(cos(env->obj->angle * M_PI / 180), 2) * \
		ft_scalar(ft_vect_op(env->cam.pixel, '-', \
		ft_vect_op2(ft_scalar(env->cam.pixel, env->obj->dir), '*', \
		env->obj->dir)), ft_vect_op(env->cam.pixel, '-', \
		ft_vect_op2(ft_scalar(env->cam.pixel, env->obj->dir), '*', \
		env->obj->dir))) - pow(sin(env->obj->angle * M_PI / 180), 2) * \
		pow(ft_scalar(env->cam.pixel, env->obj->dir), 2);
	env->calc.b = 2 * pow(cos(env->obj->angle * M_PI / 180), 2) * \
		ft_scalar(ft_vect_op(env->cam.pixel, '-', \
		ft_vect_op2(ft_scalar(env->cam.pixel, env->obj->dir), '*', \
		env->obj->dir)), ft_vect_op(env->calc.delta_p, '-', \
		ft_vect_op2(ft_scalar(env->calc.delta_p, env->obj->dir), '*', \
		env->obj->dir))) - 2 * pow(sin(env->obj->angle * M_PI / 180), 2) * \
		ft_scalar(env->cam.pixel, env->obj->dir) * ft_scalar(env->calc.delta_p, \
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
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
		(2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
		(2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
		(2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
		(2 * env->calc.a);
}

/*void	ft_calc_cyl(t_env *env)
{
	t_vect	cyl.directeur;

	cyl.directeur.x = 0;
	cyl.directeur.y = 0;
	cyl.directeur.z = 1;
	cyl.directeur = ft_vect_rot(cyl.directeur, env->obj.dir.z, 1);
	cyl.directeur = ft_vect_rot(cyl.directeur, env->obj.dir.y, 2);
	cyl.directeur = (cyl.directeur.x != 1 && cyl.directeur.x != -1) ? ft_vect_rot(cyl.directeur, env->obj.dir.x, 3) : ft_vect_rot(cyl.directeur, env->obj.dir.x, 1);
	env->calc.delta_p = ft_vect_op(env->cam.pos, '-', env->obj.pos);
	env->calc.a = ft_scalar(env->cam.pixel, env->cam.pixel) - pow(ft_scalar(env->cam.pixel,cyl.directeur),2);
	env->calc.b = 2*(ft_scalar(env->cam.pixel,ft_vect_op(env->cam.pos,'-',env->obj.pos)) - ft_scalar(env->cam.pixel,cyl.directeur)*ft_scalar(ft_vect_op(env->cam.pos,'-',env->obj.pos),cyl.directeur));
	env->calc.c = ft_scalar(ft_vect_op(env->cam.pos,'-',env->obj.pos),ft_vect_op(env->cam.pos,'-',env->obj.pos)) - pow(ft_scalar(ft_vect_op(env->cam.pos,'-',env->obj.pos), cyl.directeur),2) - pow(env->obj.radius,2);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a);
}*/
