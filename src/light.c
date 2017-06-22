/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:37:30 by mawasche          #+#    #+#             */
/*   Updated: 2017/06/22 16:55:58 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_normal_cone(t_env *env)
{
	env->tmp.reflexion->solution_point.x = env->tmp.ray_pos.x - \
		env->tmp.current->pos.x;
	env->tmp.reflexion->solution_point.y = env->tmp.ray_pos.y - \
		env->tmp.current->pos.y;
	env->tmp.reflexion->solution_point.z = env->tmp.ray_pos.z - \
		env->tmp.current->pos.z;
	env->tmp.reflexion->solution_point = ft_vect_rot(env->tmp.reflexion->solution_point,\
		-env->tmp.current->angles.z, 1);
	env->tmp.reflexion->solution_point = ft_vect_rot(env->tmp.reflexion->solution_point, \
		-env->tmp.current->angles.y, 2);
	env->tmp.reflexion->solution_point = (env->tmp.reflexion->solution_point.x != 1 && \
		env->tmp.reflexion->solution_point.x != -1) ? \
		ft_vect_rot(env->tmp.reflexion->solution_point, -env->tmp.current->angles.x, 3) :\
		ft_vect_rot(env->tmp.reflexion->solution_point, -env->tmp.current->angles.x, 1);
	env->tmp.reflexion->normal_vect.x = 2 * env->tmp.reflexion->solution_point.x;
	env->tmp.reflexion->normal_vect.y = -2 * env->tmp.reflexion->solution_point.y;
	env->tmp.reflexion->normal_vect.z = 2 * env->tmp.reflexion->solution_point.z;
	env->light->norme = sqrt(pow(env->tmp.reflexion->normal_vect.x, 2) +\
		pow(env->tmp.reflexion->normal_vect.y, 2) + pow(env->tmp.reflexion->normal_vect.z, 2));
	env->tmp.reflexion->normal_vect.x /= env->light->norme;
	env->tmp.reflexion->normal_vect.y /= env->light->norme;
	env->tmp.reflexion->normal_vect.z /= env->light->norme;
}

void	ft_normal_cyl(t_env *env)
{
	env->tmp.reflexion->solution_point.x = env->tmp.ray_pos.x - \
		env->tmp.current->pos.x;
	env->tmp.reflexion->solution_point.y = env->tmp.ray_pos.y - \
		env->tmp.current->pos.y;
	env->tmp.reflexion->solution_point.z = env->tmp.ray_pos.z - \
		env->tmp.current->pos.z;
	env->tmp.reflexion->solution_point = ft_vect_rot(env->tmp.reflexion->solution_point,\
		-env->tmp.current->angles.z, 1);
	env->tmp.reflexion->solution_point = ft_vect_rot(env->tmp.reflexion->solution_point, \
		-env->tmp.current->angles.y, 2);
	env->tmp.reflexion->solution_point = (env->tmp.reflexion->solution_point.x != 1 && \
		env->tmp.reflexion->solution_point.x != -1) ? \
		ft_vect_rot(env->tmp.reflexion->solution_point, -env->tmp.current->angles.x, 3) :\
		ft_vect_rot(env->tmp.reflexion->solution_point, -env->tmp.current->angles.x, 1);
	env->tmp.reflexion->normal_vect.x = 2 * env->tmp.reflexion->solution_point.x;
	env->tmp.reflexion->normal_vect.y = 2 * env->tmp.reflexion->solution_point.y;
	env->tmp.reflexion->normal_vect.z = 1;
	env->light->norme = sqrt(pow(env->tmp.reflexion->normal_vect.x, 2) +\
		pow(env->tmp.reflexion->normal_vect.y, 2) + pow(env->tmp.reflexion->normal_vect.z, 2));
	env->tmp.reflexion->normal_vect.x /= env->light->norme;
	env->tmp.reflexion->normal_vect.y /= env->light->norme;
	env->tmp.reflexion->normal_vect.z /= env->light->norme;
}

void	ft_normal_plane(t_env *env)
{
	env->tmp.reflexion->normal_vect.x = env->tmp.current->dir.x;
	env->tmp.reflexion->normal_vect.y = env->tmp.current->dir.y;
	env->tmp.reflexion->normal_vect.z = env->tmp.current->dir.z;
	env->light->norme = sqrt(pow(env->tmp.reflexion->normal_vect.x, 2) +\
			pow(env->tmp.reflexion->normal_vect.y, 2) + pow(env->tmp.reflexion->normal_vect.z, 2));
	env->tmp.reflexion->normal_vect.x /= env->light->norme;
	env->tmp.reflexion->normal_vect.y /= env->light->norme;
	env->tmp.reflexion->normal_vect.z /= env->light->norme;
}

void	ft_normal_sphere(t_env *env)
{
	env->tmp.reflexion->normal_vect.x = env->tmp.ray_pos.x -\
							   env->tmp.current->pos.x;
	env->tmp.reflexion->normal_vect.y = env->tmp.ray_pos.y -\
							   env->tmp.current->pos.y;
	env->tmp.reflexion->normal_vect.z = env->tmp.ray_pos.z -\
							   env->tmp.current->pos.z;
	env->light->norme = sqrt(pow(env->tmp.reflexion->normal_vect.x, 2) +\
			pow(env->tmp.reflexion->normal_vect.y, 2) + pow(env->tmp.reflexion->normal_vect.z, 2));
	env->tmp.reflexion->normal_vect.x /= env->light->norme;
	env->tmp.reflexion->normal_vect.y /= env->light->norme;
	env->tmp.reflexion->normal_vect.z /= env->light->norme;
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
	t_vect	tmp;

	tmp = env->tmp.ray_pos;
	test = env->light;
	env->tmp.power = 0;
	while(env->light)
	{
    env->tmp.reflexion->solution_point = ft_calc_sol(env);
	env->light->light_vect.x = env->light->pos.x - env->tmp.reflexion->solution_point.x;
	env->light->light_vect.y = env->light->pos.y - env->tmp.reflexion->solution_point.y;
	env->light->light_vect.z = env->light->pos.z - env->tmp.reflexion->solution_point.z;
	env->light->norme = sqrt(pow(env->light->light_vect.x,2) +\
			pow(env->light->light_vect.y,2) + pow(env->light->light_vect.z,2));
	env->light->light_vect.x /= env->light->norme;
	env->light->light_vect.y /= env->light->norme;
	env->light->light_vect.z /= env->light->norme;
	env->tmp.ray_pos = env->tmp.reflexion->solution_point;
	ft_normal_vect(env);
	env->tmp.reflexion->power = env->tmp.reflexion->normal_vect.x * env->light->light_vect.x +\
					   env->tmp.reflexion->normal_vect.y *env->light->light_vect.y +\
					   env->tmp.reflexion->normal_vect.z * env->light->light_vect.z;
	if (env->tmp.reflexion->power < 0)
		env->tmp.reflexion->power = 0;
	env->tmp.power += env->tmp.reflexion->power;
	env->light = env->light->next;
	}
	env->light = test;
	env->tmp.reflexion->power = (env->tmp.power <= 1) ? env->tmp.power : 1;
	env->tmp.ray_pos = tmp;
}
