/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:25:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/05/31 15:13:02 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_env(t_env *env)
{
	env->check.direction = 0;
	env->check.position = 0;
	env->check.radius = 0;
	env->check.color = 0;
	env->parse.type = 0;
	env->parse.objects = 0;
	env->parse.lights = 0;
	env->parse.cam = 0;
	env->parse.line = NULL;
}
