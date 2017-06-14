/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:30:02 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/12 11:47:08 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_fill_cam(t_env *env)
{
	int		i;

	i = -1;
	if (ft_strequ(env->parse.split[0], "position") == 1 && \
						env->parse.type == CAM)
		ft_pos_cam(env, i);
	else if (ft_strequ(env->parse.split[0], "direction") == 1 && \
			env->parse.type == CAM)
	{
		env->check.direction = 1;
		while (env->parse.split[++i])
		{
			if (ft_strequ(env->parse.split[i], "x") == 1 && (i + 2) \
					<= env->parse.tablen)
				env->cam.dir.x = ft_atoi(env->parse.split[i + 2]);
			if (ft_strequ(env->parse.split[i], "y") == 1 && (i + 2) \
					<= env->parse.tablen)
				env->cam.dir.y = ft_atoi(env->parse.split[i + 2]);
			if (ft_strequ(env->parse.split[i], "z") == 1 && (i + 2) \
					<= env->parse.tablen)
				env->cam.dir.z = ft_atoi(env->parse.split[i + 2]);
		}
	}
}

void	ft_pos_cam(t_env *env, int i)
{
	env->check.position = 1;
	while (env->parse.split[++i])
	{
		if (ft_strequ(env->parse.split[i], "x") == 1 && (i + 2) \
				<= env->parse.tablen)
			env->cam.pos.x = \
						ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "y") == 1 && (i + 2) \
				<= env->parse.tablen)
			env->cam.pos.y = \
						ft_atoi(env->parse.split[i + 2]);
		if (ft_strequ(env->parse.split[i], "z") == 1 && (i + 2) \
				<= env->parse.tablen)
			env->cam.pos.z = \
						ft_atoi(env->parse.split[i + 2]);
	}
}
