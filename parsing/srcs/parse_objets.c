/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:49:32 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/02 17:18:08 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_objects(t_env *env)
{
	ft_check_obj_types(env);
	if ((env->parse.type_obj == SPHERE && ft_strequ(env->parse.split[0], \
		"sphere") == 0) || (env->parse.type_obj == PLANE && \
		ft_strequ(env->parse.split[0], "plane") == 0) || \
			(env->parse.type_obj == CYL && ft_strequ(env->parse.split[0], \
					"cylinder") == 0) || (env->parse.type_obj == CONE && \
				ft_strequ(env->parse.split[0], "cone") == 0))
		ft_parse_objects(env);
	ft_end_obj(env);
}

void	ft_parse_objects(t_env *env)
{
	int		i;

	i = 0;
	if (env->parse.type_obj == SPHERE && ft_strequ(env->parse.split[0], \
								"radius") && 2 <= env->parse.tablen)
	{
		env->check.radius = 1;
		((env->tmp.radius = ft_atoi(env->parse.split[2])) == 0) ? \
															ft_error() : "";
	}
	else if (ft_strequ(env->parse.split[0], "color") == 1)
		ft_parse_color(env, i);
	else if (ft_strequ(env->parse.split[0], "position") == 1)
		ft_parse_position(env, i);
	else if (ft_strequ(env->parse.split[0], "direction") == 1)
		ft_parse_direction(env, i);
}

void	ft_parse_position(t_env *env, int i)
{
	env->check.position = 1;
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "x") && (i + 2) <= env->parse.tablen)
			env->tmp.pos_x = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "y") && (i + 2) <= env->parse.tablen)
			env->tmp.pos_y = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "z") && (i + 2) <= env->parse.tablen)
			env->tmp.pos_z = ft_atoi(env->parse.split[i + 2]);
		i++;
	}
}

void	ft_parse_direction(t_env *env, int i)
{
	env->check.direction = 1;
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "x") && (i + 2) <= env->parse.tablen)
			env->tmp.dir_x = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "y") && (i + 2) <= env->parse.tablen)
			env->tmp.dir_y = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "z") && (i + 2) <= env->parse.tablen)
			env->tmp.dir_z = ft_atoi(env->parse.split[i + 2]);
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
			env->tmp.red = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "blue") && (i + 2) \
												<= env->parse.tablen)
			env->tmp.blue = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "green") && (i + 2) \
				<= env->parse.tablen)
			env->tmp.green = ft_atoi(env->parse.split[i + 2]);
		i++;
	}
}
