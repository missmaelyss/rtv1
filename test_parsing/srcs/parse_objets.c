/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:49:32 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/01 14:30:05 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_objects(t_env *env)
{
	ft_check_obj_types(env);
	if (env->parse.type_obj == SPHERE && ft_strequ(env->parse.split[0], \
														"sphere") == 0)
		ft_is_sphere(env);
}

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

void	ft_parse_sphere(t_env *env)
{
	int		i;

	i = 0;
	if (ft_strequ(env->parse.split[0], "radius") && 2 <= env->parse.tablen)
	{
		env->check.radius = 1;
		((env->tmp.radius = ft_atoi(env->parse.split[2])) == 0) ? \
															ft_error() : "";
	}
	else if (ft_strequ(env->parse.split[0], "color") == 1)
		ft_parse_color(env, i);
	else if (ft_strequ(env->parse.split[0], "position") == 1)
		ft_parse_position(env, i);

}

void	ft_parse_position(t_env *env, int i)
{
	while (env->parse.split[i])
	{
		if (ft_strequ(env->parse.split[i], "x") && (i + 2) <= env->parse.tablen)
			env->tmp.pos_x = ft_atoi(env>parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "y") && (i + 2) <= env->parse.tablen)
			env->tmp.pos_y = ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "z") && (i + 2) <= env->parse.tablen)
			env->tmp.pos_z = ft_atoi(env->parse.split[i + 2]);
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
