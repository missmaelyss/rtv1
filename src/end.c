/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:28:09 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 11:02:56 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_end_obj(t_env *env)
{
	if ((ft_strequ(env->parse.split[0], "/sphere") || \
		ft_strequ(env->parse.split[0], "/cylinder") || \
		ft_strequ(env->parse.split[0], "/plane") || \
		ft_strequ(env->parse.split[0], "/cone") || ft_strequ(env->parse.\
		split[0], "/parabole") || ft_strequ(env->parse.split[0], "/ellipse")) \
		&& env->parse.type == OBJ)
	{
		ft_check_error_obj(env);
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

void	ft_check_error_obj(t_env *env)
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
}

void	ft_end_lights(t_env *env)
{
	if ((ft_strequ(env->parse.split[0], "/basic") || \
			ft_strequ(env->parse.split[0], "/spotlight")) && \
			env->parse.type == LIGHT)
	{
		if ((!env->check.direction && (env->parse.type_light == SPOT)) || \
				!env->check.position)
			ft_error();
		ft_init_check(env);
		if (env->light == NULL)
		{
			env->light = ft_fill_light(env);
			env->tmp_light = env->light;
		}
		else
		{
			env->tmp_light->next = ft_fill_light(env);
			env->tmp_light = env->tmp_light->next;
		}
		ft_init_tmp(env);
		env->parse.type_light = 0;
	}
}
