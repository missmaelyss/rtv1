/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:00:09 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/21 14:02:40 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_lights(t_env *env)
{
	ft_check_light_types(env);
	if (((env->parse.type_light == BASIC && !ft_strequ(env->parse.split[0], \
			"basic")) || (env->parse.type_light == SPOT && \
			!ft_strequ(env->parse.split[0], "spotlight")) || \
			(env->parse.type_light == POINT && !ft_strequ(env->parse.split[0], \
			"pointlight"))) && env->parse.type == LIGHT)
	{
		env->parse.lights++;
		ft_parse_lights(env);
	}
	ft_end_lights(env);
}

void	ft_parse_lights(t_env *env)
{
	int		i;

	i = 0;
	if ((env->parse.type_light == SPOT || env->parse.type_light == POINT) &&\
			ft_strequ(env->parse.split[0], "direction"))
		ft_parse_angles(env, i);
	else if (ft_strequ(env->parse.split[0], "position"))
		ft_parse_position(env, i);
	else if (ft_strequ(env->parse.split[0], "color"))
		ft_parse_color(env, i);
}
