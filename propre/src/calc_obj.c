/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:01:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 16:39:34 by ele-cren         ###   ########.fr       */
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
	env->calc.c = (pow(env->cam.pos.x - env->obj->pos.x, 2) + pow(env->cam.pos.y\
	- env->obj->pos.y, 2) + pow(env->cam.pos.z - env->obj->pos.z, 2)) - \
				  pow(env->obj->radius, 2);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
		(2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
		(2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
		(2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
		(2 * env->calc.a);
}
