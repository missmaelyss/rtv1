/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:00:09 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/06 11:41:15 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_fill_lights(t_env *env)
{
	int		i;

	i = 0;
	if (ft_strequ(env->parse.split[0], "position") == 1)
	{
		env->check.position = 1;
		while (env->parse.split[i])
		{
			if (ft_strequ(env->parse.split[i], "x") && (i + 2) \
										<= env->parse.tablen)
				env->light.pos.x = ft_atoi(env->parse.split[i + 2]);
			else if (ft_strequ(env->parse.split[i], "y") && (i + 2) \
										<= env->parse.tablen)
				env->light.pos.y = ft_atoi(env->parse.split[i + 2]);
			else if (ft_strequ(env->parse.split[i], "z") && (i + 2) \
										<= env->parse.tablen)
				env->light.pos.z = ft_atoi(env->parse.split[i + 2]);
			i++;
		}
	}
}
