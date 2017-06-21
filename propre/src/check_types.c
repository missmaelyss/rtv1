/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:34:18 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/19 13:31:26 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_check_obj_types(t_env *env)
{
	if (ft_strequ(env->parse.split[0], "sphere") == 1)
		env->parse.type_obj = SPHERE;
	else if (ft_strequ(env->parse.split[0], "plane") == 1)
		env->parse.type_obj = PLANE;
	else if (ft_strequ(env->parse.split[0], "cylinder") == 1)
		env->parse.type_obj = CYL;
	else if (ft_strequ(env->parse.split[0], "cone") == 1)
		env->parse.type_obj = CONE;
	else if (ft_strequ(env->parse.split[0], "parabole"))
		env->parse.type_obj = PARA;
	else if (ft_strequ(env->parse.split[0], "ellipse"))
		env->parse.type_obj = ELL;
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
		env->parse.type = 0;
		ft_init_check(env);
	}
}

void	ft_check_light_types(t_env *env)
{
	if (ft_strequ(env->parse.split[0], "basic"))
		env->parse.type_light = BASIC;
	else if (ft_strequ(env->parse.split[0], "spotlight"))
		env->parse.type_light = SPOT;
	else if (ft_strequ(env->parse.split[0], "pointlight"))
		env->parse.type_light = POINT;
}
