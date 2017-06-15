/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:34:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 13:48:51 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_obj_types(t_env *env)
{
	if (ft_strequ(env->parse.split[0], "sphere") == 1)
	{
		env->parse.objects++;
		env->parse.type_obj = SPHERE;
	}
	else if (ft_strequ(env->parse.split[0], "plane") == 1)
	{
		env->parse.objects++;
		env->parse.type_obj = PLANE;
	}
	else if (ft_strequ(env->parse.split[0], "cylinder") == 1)
	{
		env->parse.objects++;
		env->parse.type_obj = CYL;
	}
	else if (ft_strequ(env->parse.split[0], "cone") == 1)
	{
		env->parse.objects++;
		env->parse.type_obj = CONE;
	}
}

void	ft_check_types(t_env *env)
{
	if (ft_strequ("camera", env->parse.split[0]) == 1)
	{
		env->parse.type = CAM;
		env->parse.cam++;
	}
	else if (ft_strequ("objects", env->parse.split[0]) == 1)
		env->parse.type = OBJ;
	else if (ft_strequ("light", env->parse.split[0]) == 1)
	{
		env->parse.type = LIGHT;
		env->parse.lights++;
	}
	if (ft_strequ("/camera", env->parse.split[0]) == 1 || \
			ft_strequ("/light", env->parse.split[0]) == 1 || \
			ft_strequ("/objects", env->parse.split[0]) == 1)
	{
		(ft_strequ("/camera", env->parse.split[0]) == 1 && (env->check.position\
						== 0 || env->check.direction == 0)) ? ft_error() : "";
		(ft_strequ("/light", env->parse.split[0]) == 1 && (env->check.position\
						== 0)) ? ft_error() : "";
		env->parse.type = 0;
		ft_init_check(env);
	}
}

void	ft_end_obj(t_env *env)
{
	if ((ft_strequ(env->parse.split[0], "/sphere") || \
		ft_strequ(env->parse.split[0], "/cylinder") || \
		ft_strequ(env->parse.split[0], "/plane") || \
		ft_strequ(env->parse.split[0], "/cone")) && env->parse.type == OBJ)
	{
		if ((!env->check.position && !ft_strequ(env->parse.split[0], "/plane"))\
			|| !env->check.color || \
		((ft_strequ(env->parse.split[0], "/sphere") || \
		  ft_strequ(env->parse.split[0], "/cylinder")) && \
		!env->check.radius) || (!env->check.direction && \
		!ft_strequ(env->parse.split[0], "/sphere")) || (!env->check.angle && \
		ft_strequ(env->parse.split[0], "/cone")))
			ft_error();
		ft_init_check(env);
		if (env->obj == NULL)
		{
			env->obj = ft_fill_obj(env);
			env->tmp_obj = env->obj;
		}
		else
		{
			env->tmp_obj->next = ft_fill_obj(env);
			env->tmp_obj = env->tmp_obj->next;
		}
		ft_init_tmp(env);
		env->parse.type_obj = 0;
	}
}
