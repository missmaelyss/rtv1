/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:06:40 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/06 11:38:29 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_parse(t_env *env, char *av)
{
	ft_init_env(env);
	ft_init_tmp(env);
	if ((env->parse.fd = open(av, O_RDONLY)) == -1)
		ft_error_file();
	while ((get_next_line(env->parse.fd, &env->parse.line)) == 1)
	{
		env->parse.split = ft_strsplit_m(env->parse.line, "\" \t<>\n");
		env->parse.tablen = ft_tablen(env->parse.split);
		ft_check_types(env);
		(env->parse.type == CAM && ft_strequ(env->parse.split[0], "camera") \
		 == 0) ? ft_fill_cam(env) : "";
		(env->parse.type == OBJ && ft_strequ(env->parse.split[0], "objects") \
		 == 0) ? ft_check_objects(env) : "";
		(env->parse.type == LIGHT && ft_strequ(env->parse.split[0], "light") \
		 == 0) ? ft_fill_lights(env) : "";
		ft_tabdel(&env->parse.split);
		ft_strdel(&env->parse.line);
	}
	if (env->parse.cam == 0)
		ft_error();
	if (close(env->parse.fd) == -1)
		ft_error_file();
}
