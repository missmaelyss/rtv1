/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:25:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/02 14:18:04 by ele-cren         ###   ########.fr       */
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
	env->tmp_obj = NULL;
}

void	ft_init_tmp(t_env *env)
{
	env->tmp.pos_x = 0;
	env->tmp.pos_y = 0;
	env->tmp.pos_z = 0;
	env->tmp.radius = 0;
	env->tmp.dir_x = 0;
	env->tmp.dir_y = 0;
	env->tmp.dir_z = 0;
	env->tmp.red = 0;
	env->tmp.green = 0;
	env->tmp.blue = 0;
}

void	ft_init_check(t_env *env)
{
	env->check.position = 0;
	env->check.direction = 0;
	env->check.color = 0;
	env->check.radius = 0;
}
