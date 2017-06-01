/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:06:40 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/01 14:26:12 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_parse(t_env *env, char *av)
{
	ft_init_env(env);
	if ((env->parse.fd = open(av, O_RDONLY)) == -1)
		ft_error_file();
	while ((get_next_line(env->parse.fd, &env->parse.line)) == 1)
	{
		env->parse.split = ft_strsplit_m(env->parse.line, "\" \t<>\n");
		env->parse.tablen = ft_tablen(env->parse.split);
		ft_check_types(env);
		if (env->parse.type == CAM && ft_strequ(env->parse.split[0], \
					"camera") == 0)
			ft_fill_cam(env);
		else if (env->parse.type == OBJ)
			ft_check_objects(env);
		ft_tabdel(&env->parse.split);
		ft_strdel(&env->parse.line);
	}
	if (env->parse.cam == 0)
		ft_error();
	if (close(env->parse.fd) == -1)
		ft_error_file();
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
		env->check.direction = 0;
		env->check.position = 0;
	}
}
