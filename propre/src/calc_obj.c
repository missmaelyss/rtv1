/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:01:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 12:41:25 by marnaud          ###   ########.fr       */
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

void	ft_calc_plan(t_env *env)
  {
	t_vect	sol;
      double  hight;

	sol.x = 0;
	sol.y = 0;
	sol.z = 1;
	hight = env->obj->pos.z;
	sol = rotation_matricielle(sol, env->obj->pos.z, 1);
	sol = rotation_matricielle(sol, env->obj->pos.y, 2);
	sol = (sol.x != 1 && sol.x != -1) ? rotation_matricielle(sol, env->obj->pos.x, 3) : rotation_matricielle(sol, env->obj->pos.x, 1);
	env->calc.solution = -((sol.x*(env->cam.pos.x - 1) + sol.y*(env->cam.pos.y - 1) + sol.z*(env->cam.pos.z - (-1)) + hight) / (sol.x * env->cam.pixel.x + sol.y * env->cam.pixel.y + sol.z * env->cam.pixel.z));
  }
/*
void	ft_calc_cone(t_env *env)
{
	t_vect	cone.directeur;

	cone.directeur.x = 0;
	cone.directeur.y = 0;
	cone.directeur.z = 1;
	cone.directeur = rotation_matricielle(cone.directeur, env->obj.dir.z, 1);
	cone.directeur = rotation_matricielle(cone.directeur, env->obj.dir.y, 2);
	cone.directeur = (cone.directeur.x != 1 && cone.directeur.x != -1) ? rotation_matricielle(cone.directeur, env->obj.dir.x, 3) : rotation_matricielle(cone.directeur, env->obj.dir.x, 1);
	env->calc.delta_p = operation_vct(env->cam.pos, '-', env->obj.pos);
	env->calc.a = pow(cos(env->obj.angle * M_PI / 180), 2) * scalaire(operation_vct(env->cam.pixel, '-', operation2_vct(scalaire(env->cam.pixel, cone.directeur), '*', cone.directeur)), operation_vct(env->cam.pixel, '-', operation2_vct(scalaire(env->cam.pixel, cone.directeur), '*', cone.directeur))) - \
				  pow(sin(env->obj.angle * M_PI / 180), 2) * pow(scalaire(env->cam.pixel, cone.directeur), 2);

	env=>calc.b = 2 * pow(cos(env->obj.angle * M_PI / 180), 2) * scalaire(operation_vct(env->cam.pixel, '-', operation2_vct(scalaire(env->cam.pixel, cone.directeur), '*', cone.directeur)), operation_vct(env->calc.delta_p, '-', operation2_vct(scalaire(env->calc.delta_p, cone.directeur), '*', cone.directeur))) - \
		2 * pow(sin(env->obj.angle * M_PI / 180), 2) * scalaire(env->cam.pixel, cone.directeur) * scalaire(env->calc.delta_p, cone.directeur);

	env->calc.c = pow(cos(env->obj.angle * M_PI / 180), 2) * scalaire(operation_vct(env->calc.delta_p, '-', operation2_vct(scalaire(env->calc.delta_p, cone.directeur), '*', cone.directeur)), operation_vct(env->calc.delta_p, '-', operation2_vct(scalaire(env->calc.delta_p, cone.directeur), '*', cone.directeur))) - \
				  pow(sin(env->obj.angle * M_PI / 180), 2) * pow(scalaire(env->calc.delta_p, cone.directeur), 2);

	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a);
}

void	ft_calc_cyl(t_env *env)
{
	t_vect	cyl.directeur;

	cyl.directeur.x = 0;
	cyl.directeur.y = 0;
	cyl.directeur.z = 1;
	cyl.directeur = rotation_matricielle(cyl.directeur, env->obj.dir.z, 1);
	cyl.directeur = rotation_matricielle(cyl.directeur, env->obj.dir.y, 2);
	cyl.directeur = (cyl.directeur.x != 1 && cyl.directeur.x != -1) ? rotation_matricielle(cyl.directeur, env->obj.dir.x, 3) : rotation_matricielle(cyl.directeur, env->obj.dir.x, 1);
	env->calc.delta_p = operation_vct(env->cam.pos, '-', env->obj.pos);
	env->calc.a = scalaire(env->cam.pixel, env->cam.pixel) - pow(scalaire(env->cam.pixel,cyl.directeur),2);
	env->calc.b = 2*(scalaire(env->cam.pixel,operation_vct(env->cam.pos,'-',env->obj.pos)) - scalaire(env->cam.pixel,cyl.directeur)*scalaire(operation_vct(env->cam.pos,'-',env->obj.pos),cyl.directeur));
	env->calc.c = scalaire(operation_vct(env->cam.pos,'-',env->obj.pos),operation_vct(env->cam.pos,'-',env->obj.pos)) - pow(scalaire(operation_vct(env->cam.pos,'-',env->obj.pos), cyl.directeur),2) - pow(env->obj.radius,2);
	env->calc.delta = pow(env->calc.b, 2) - (4 * env->calc.a * env->calc.c);
	if (env->calc.delta >= 0)
		env->calc.solution = (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) > (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) ? (-env->calc.b - sqrt(env->calc.delta)) / \
							 (2 * env->calc.a) : (-env->calc.b + sqrt(env->calc.delta)) / \
							 (2 * env->calc.a);
}*/
