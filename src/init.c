/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:25:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 19:02:39 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_env(t_env *env)
{
	env->check.direction = 0;
	env->check.position = 0;
	env->check.radius = 0;
	env->check.color = 0;
	env->parse.type = 0;
	env->parse.type_obj = 0;
	env->parse.objects = 0;
	env->parse.lights = 0;
	env->parse.cam = 0;
	env->parse.line = NULL;
	env->obj = NULL;
	env->light = NULL;
	env->tmp_light = NULL;
	env->tmp_obj = NULL;
	env->tmp.current = NULL;
}

void	ft_init_tmp(t_env *env)
{
	env->tmp.pos.x = 0;
	env->tmp.pos.y = 0;
	env->tmp.pos.z = 0;
	env->tmp.radius = 0;
	env->tmp.angles.x = 0;
	env->tmp.angles.y = 0;
	env->tmp.angles.z = 0;
	env->tmp.angles.h = 0;
	env->tmp.color.red = 0;
	env->tmp.color.green = 0;
	env->tmp.color.blue = 0;
	env->tmp.tile.red = 0;
	env->tmp.tile.green = 0;
	env->tmp.tile.blue = 0;
	env->tmp.tile.w = 0;
	env->tmp.tex = 0;
	env->tmp.angle = 0;
	env->tmp.refle = 0;
	env->tmp.refra = 0;
	env->tmp.fin[0] = 0;
	env->tmp.fin[1] = 0;
	env->tmp.finished = 0;
}

void	ft_init_check(t_env *env)
{
	env->check.position = 0;
	env->check.direction = 0;
	env->check.color = 0;
	env->check.radius = 0;
	env->check.angle = 0;
}

void	ft_init_start(t_env *env)
{
	env->cam.right.x = 1;
	env->cam.right.y = 0;
	env->cam.right.z = 0;
	env->cam.up.x = 0;
	env->cam.up.y = 0;
	env->cam.up.z = 1;
	env->cam.view_plane.x = env->cam.pos.x + ((env->cam.dir.x * VIEWPLANED) + \
	(env->cam.up.x * (VIEWPLANEH / 2.0 * F))) - (env->cam.right.x * \
		(VIEWPLANEW / 2.0 * F));
	env->cam.view_plane.y = env->cam.pos.y + ((env->cam.dir.y * VIEWPLANED) + \
	(env->cam.up.y * (VIEWPLANEH / 2.0 * F))) - (env->cam.right.y * \
		(VIEWPLANEW / 2.0 * F));
	env->cam.view_plane.z = env->cam.pos.z + ((env->cam.dir.z * VIEWPLANED) + \
	(env->cam.up.z * (VIEWPLANEH / 2.0 * F))) - (env->cam.right.z * \
		(VIEWPLANEW / 2.0 * F));
	/*
	env->cam.lookat = ft_vect_op(env->cam.dir, '+', env->cam.pos);
	env->cam.u = ft_vect_prod(env->cam.dir, env->cam.pos);
	env->cam.v = ft_vect_prod(env->cam.u, env->cam.dir);
	env->cam.u = ft_normalize(env->cam.u);
	env->cam.v = ft_normalize(env->cam.v);
	env->cam.view_plane_width = tan(30.0 / 2.0 * M_PI / 180);
	env->cam.aspect = WIDTHR / HEIGHT;
	env->cam.view_plane_height = env->cam.aspect * env->cam.view_plane_width;
	env->cam.bot = ft_vect_op(ft_vect_op(env->cam.lookat, '-', \
		ft_vect_op2(env->cam.view_plane_height, '*', env->cam.v)), '-', \
		ft_vect_op2(env->cam.view_plane_width, '*', env->cam.u));
	env->cam.x_inc = ft_vect_op2(WIDTHR, '/', \
		ft_vect_op2(env->cam.view_plane_width, '*', \
		ft_vect_op2(2, '*', env->cam.u)));
	env->cam.y_inc = ft_vect_op2(HEIGHT, '/', \
		ft_vect_op2(env->cam.view_plane_height, '*', \
		ft_vect_op2(2, '*', env->cam.v)));*/
}
