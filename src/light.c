/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:37:30 by mawasche          #+#    #+#             */
/*   Updated: 2017/06/20 18:06:07 by mawasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_normal_cone(t_env *env)
{
	env->light->solution_point.x = env->light->solution_point.x - \
		env->tmp.current->pos.x;
	env->light->solution_point.y = env->light->solution_point.y - \
		env->tmp.current->pos.y;
	env->light->solution_point.z = env->light->solution_point.z - \
		env->tmp.current->pos.z;
	env->light->solution_point = ft_vect_rot(env->light->solution_point,\
		env->tmp.current->angles.z, 1);
	env->light->solution_point = ft_vect_rot(env->light->solution_point, \
		env->obj->angles.y, 2);
	env->light->solution_point = (env->light->solution_point.x != 1 && \
		env->light->solution_point.x != -1) ? \
		ft_vect_rot(env->light->solution_point, env->tmp.current->angles.x, 3) :\
		ft_vect_rot(env->light->solution_point, env->tmp.current->angles.x, 1);
	env->light->normal_vect.x = 2 * env->light->solution_point.x;
	env->light->normal_vect.y = -2 * env->light->solution_point.y;
	env->light->normal_vect.z = 2 * env->light->solution_point.z;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
		pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_cyl(t_env *env)
{
	env->light->solution_point.x = env->light->solution_point.x - \
		env->tmp.current->pos.x;
	env->light->solution_point.y = env->light->solution_point.y - \
		env->tmp.current->pos.y;
	env->light->solution_point.z = env->light->solution_point.z - \
		env->tmp.current->pos.z;
	env->light->solution_point = ft_vect_rot(env->light->solution_point,\
		env->tmp.current->angles.z, 1);
	env->light->solution_point = ft_vect_rot(env->light->solution_point, \
		env->obj->angles.y, 2);
	env->light->solution_point = (env->light->solution_point.x != 1 && \
		env->light->solution_point.x != -1) ? \
		ft_vect_rot(env->light->solution_point, env->tmp.current->angles.x, 3) :\
		ft_vect_rot(env->light->solution_point, env->tmp.current->angles.x, 1);
	env->light->normal_vect.x = 2 * env->light->solution_point.x;
	env->light->normal_vect.y = 2 * env->light->solution_point.y;
	env->light->normal_vect.z = 1;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
		pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_plane(t_env *env)
{
	env->light->normal_vect.x = env->tmp.current->dir.x;
	env->light->normal_vect.y = env->tmp.current->dir.y;
	env->light->normal_vect.z = env->tmp.current->dir.z;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
			pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_sphere(t_env *env)
{
	env->light->normal_vect.x = env->light->solution_point.x -\
							   env->tmp.current->pos.x;
	env->light->normal_vect.y = env->light->solution_point.y -\
							   env->tmp.current->pos.y;
	env->light->normal_vect.z = env->light->solution_point.z -\
							   env->tmp.current->pos.z;
	env->light->norme = sqrt(pow(env->light->normal_vect.x, 2) +\
			pow(env->light->normal_vect.y, 2) + pow(env->light->normal_vect.z, 2));
	env->light->normal_vect.x /= env->light->norme;
	env->light->normal_vect.y /= env->light->norme;
	env->light->normal_vect.z /= env->light->norme;
}

void	ft_normal_vect(t_env *env)
{
	void	(*ft_normal[4])(t_env *);

	ft_normal[0] = ft_normal_sphere;
	ft_normal[1] = ft_normal_plane;
	ft_normal[2] = ft_normal_cyl;
	ft_normal[3] = ft_normal_cone;
	ft_normal[env->tmp.current->type - 1](env);
}

void	ft_light(t_env *env)
{
	t_light	*test;

	test = env->light;
	env->tmp.power = 0;
	while(env->light)
	{
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
	env->light->light_vect.x /= env->light->norme;
	env->light->light_vect.y /= env->light->norme;
	env->light->light_vect.z /= env->light->norme;
	ft_normal_vect(env);
	env->light->power = env->light->normal_vect.x * env->light->light_vect.x +\
					   env->light->normal_vect.y *env->light->light_vect.y +\
					   env->light->normal_vect.z * env->light->light_vect.z;
	if (env->light->power < 0)
		env->light->power = 0;
	env->tmp.power += env->light->power;
	env->light = env->light->next;
	}
	env->light = test;
	env->light->power = (env->tmp.power <= 1) ? env->tmp.power : 1;
}
