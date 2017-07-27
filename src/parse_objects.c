/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:13:20 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 14:44:29 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		ft_check_objects(t_env *env)
{
	ft_check_obj_types(env);
	if (((env->parse.type_obj == SPHERE && !ft_strequ(env->parse.split[0], \
		"sphere")) || (env->parse.type_obj == PLANE && \
		!ft_strequ(env->parse.split[0], "plane")) || \
		(env->parse.type_obj == CYL && !ft_strequ(env->parse.split[0], \
		"cylinder")) || (env->parse.type_obj == CONE && \
		!ft_strequ(env->parse.split[0], "cone")) || (env->parse.\
		type_obj == PARA && !ft_strequ(env->parse.split[0], "parabole")) || \
		(env->parse.type_obj == ELL && !ft_strequ(env->parse.split[0], \
		"ellipse"))) && env->parse.type == OBJ)
		ft_parse_objects(env);
	ft_end_obj(env);
}

static void	ft_parse_objects2(t_env *env, int i)
{
	if (ft_strequ(env->parse.split[0], "color") == 1)
		ft_parse_color(env, i);
	else if (ft_strequ(env->parse.split[0], "position") == 1)
		ft_parse_position(env, i);
	else if (ft_strequ(env->parse.split[0], "angles") == 1)
		ft_parse_angles(env, i);
	else if (ft_strequ(env->parse.split[0], "reflexion") && 2 <= \
			env->parse.tablen)
	{
		env->tmp.refle = ft_atoi(env->parse.split[2]);
		(env->tmp.refle < 0 || env->tmp.refle > 100) ? ft_error() : "";
	}
	else if (ft_strequ(env->parse.split[0], "refraction"))
		ft_parse_refraction(env, i);
	else if (ft_strequ(env->parse.split[0], "texture") && 2 <= \
			env->parse.tablen)
		ft_parse_tex(env);
	else if (ft_strequ(env->parse.split[0], "finished"))
	{
		env->tmp.finished = 1;
		ft_parse_finished(env, i);
	}
}

void		ft_parse_objects(t_env *env)
{
	int		i;

	i = 0;
	if ((env->parse.type_obj == SPHERE || env->parse.type_obj == CYL) && \
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
	else
		ft_parse_objects2(env, i);
}

void		ft_parse_tex(t_env *env)
{
	if (ft_strequ(env->parse.split[2], "checker"))
		env->tmp.tex = CHECKER;
	else if (ft_strequ(env->parse.split[2], "moon"))
		env->tmp.tex = MOON;
	else if (ft_strequ(env->parse.split[2], "sun"))
		env->tmp.tex = SUN;
	else if (ft_strequ(env->parse.split[2], "earth"))
		env->tmp.tex = EARTH;
	else if (ft_strequ(env->parse.split[2], "garden"))
		env->tmp.tex = GARDEN;
}

void		ft_parse_refraction(t_env *env, int i)
{
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "refra") && (i + 2) <= \
				env->parse.tablen)
		{
			env->tmp.refra = ft_atoi(env->parse.split[i + 2]);
			(env->tmp.refra < 0 || env->tmp.refra > 7) ? ft_error() : "";
		}
		if (ft_strequ(env->parse.split[i], "trans") && (i + 2) <= \
				env->parse.tablen)
		{
			env->tmp.refra = ft_atoi(env->parse.split[i + 2]);
			(env->tmp.refra_trans < 0 || env->tmp.refra_trans > 100) ? \
				ft_error() : "";
		}
		i++;
	}
}
