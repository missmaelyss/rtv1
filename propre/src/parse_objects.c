/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:13:20 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/21 13:24:02 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_objects(t_env *env)
{
	ft_check_obj_types(env);
	if (((env->parse.type_obj == SPHERE && !ft_strequ(env->parse.split[0], \
		"sphere")) || (env->parse.type_obj == PLANE && !ft_strequ(env->parse\
		.split[0], "plane")) || (env->parse.type_obj == CYL && \
		!ft_strequ(env->parse.split[0], "cylinder")) || (env->parse.type_obj\
		== CONE && !ft_strequ(env->parse.split[0], "cone")) || (env->parse.\
		type_obj == PARA && !ft_strequ(env->parse.split[0], "parabole")) || \
		(env->parse.type_obj == ELL && !ft_strequ(env->parse.split[0], \
		"ellipse"))) && env->parse.type == OBJ)
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
	else if (ft_strequ(env->parse.split[0], "tiles"))
	{
		env->tmp.tex = TILE;
		ft_parse_tiles(env, i);
	}
	else if (ft_strequ(env->parse.split[0], "reflexion") && 2 <= \
			env->parse.tablen)
		env->tmp.ref = ft_atoi(env->parse.split[2]);
}

void	ft_parse_tiles(t_env *env, int i)
{
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "red") && (i + 2) \
								<= env->parse.tablen)
			env->tmp.tile.red = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "blue") && (i + 2) \
												<= env->parse.tablen)
			env->tmp.tile.blue = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "green") && (i + 2) \
				<= env->parse.tablen)
			env->tmp.tile.green = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "w") && (i + 2) <= env->parse.tablen)
			env->tmp.tile.w = ft_atoi(env->parse.split[i + 2]);
		i++;
	}
}
