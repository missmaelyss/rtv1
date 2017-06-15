/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:13:20 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 16:17:29 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_objects(t_env *env)
{
	ft_check_obj_types(env);
	if (((env->parse.type_obj == SPHERE && ft_strequ(env->parse.split[0], \
		"sphere") == 0) || (env->parse.type_obj == PLANE && \
		ft_strequ(env->parse.split[0], "plane") == 0) || \
			(env->parse.type_obj == CYL && ft_strequ(env->parse.split[0], \
					"cylinder") == 0) || (env->parse.type_obj == CONE && \
				ft_strequ(env->parse.split[0], "cone") == 0)) \
									&& env->parse.type == OBJ)
	{
		env->parse.objects++;
		ft_parse_objects(env);
	}
	ft_end_obj(env);
}

void	ft_parse_objects(t_env *env)
{
	int		i;

	i = 0;
	if ((env->parse.type_obj == SPHERE || env->parse.type_obj == CYL)&& \
			ft_strequ(env->parse.split[0], "radius") && 2 <= env->parse.tablen)
	{
		env->check.radius = 1;
		((env->tmp.radius = ft_atoi(env->parse.split[2])) == 0) ? \
															ft_error() : "";
	}
	else if ((env->parse.type_obj == CONE && \
		ft_strequ(env->parse.split[0], "angle")) && 2 <= env->parse.tablen)
	{
		env->check.angle = 1;
		env->tmp.angle = ft_atoi(env->parse.split[2]);
		(env->tmp.angle <= 0 || env->tmp.angle >= 180) ? ft_error() : "";
	}
	else if (ft_strequ(env->parse.split[0], "color") == 1)
		ft_parse_color(env, i);
	else if (ft_strequ(env->parse.split[0], "position") == 1)
		ft_parse_position(env, i);
	else if (ft_strequ(env->parse.split[0], "angles") == 1)
		ft_parse_angles(env, i);
}

void	ft_parse_position(t_env *env, int i)
{
	env->check.position = 1;
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "x") && (i + 2) <= env->parse.tablen)
			env->tmp.pos.x = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "y") && (i + 2) <= env->parse.tablen)
			env->tmp.pos.y = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "z") && (i + 2) <= env->parse.tablen)
			env->tmp.pos.z = ft_atoi(env->parse.split[i + 2]);
		i++;
	}
}

void	ft_parse_angles(t_env *env, int i)
{
	env->check.direction = 1;
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "x") && (i + 2) <= env->parse.tablen)
			env->tmp.angles.x = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "y") && (i + 2) <= env->parse.tablen)
			env->tmp.angles.y = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "z") && (i + 2) <= env->parse.tablen)
			env->tmp.angles.z = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "h") && (i + 2) <= env->parse.tablen)
			env->tmp.angles.h = ft_atoi(env->parse.split[i + 2]);
		i++;
	}
}

void	ft_parse_color(t_env *env, int i)
{
	env->check.color = 1;
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "red") && (i + 2) \
								<= env->parse.tablen)
			env->tmp.color.red = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "blue") && (i + 2) \
												<= env->parse.tablen)
			env->tmp.color.blue = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "green") && (i + 2) \
				<= env->parse.tablen)
			env->tmp.color.green = ft_atoi(env->parse.split[i + 2]);
		i++;
	}
}
