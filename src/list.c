/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:08:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/21 14:04:22 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_obj	*ft_fill_obj(t_env *env)
{
	t_obj	*obj;

	obj = NULL;
	if ((obj = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	obj->type = env->parse.type_obj;
	obj->radius = env->tmp.radius;
	obj->angle = env->tmp.angle;
	obj->pos.x = env->tmp.pos.x;
	obj->pos.y = env->tmp.pos.y;
	obj->pos.z = env->tmp.pos.z;
	obj->angles.x = env->tmp.angles.x;
	obj->angles.y = env->tmp.angles.y;
	obj->angles.z = env->tmp.angles.z;
	obj->angles.h = env->tmp.angles.h;
	obj->color.red = env->tmp.color.red;
	obj->color.green = env->tmp.color.green;
	obj->color.blue = env->tmp.color.blue;
	obj->tex = env->tmp.tex;
	obj->tile.red = env->tmp.tile.red;
	obj->tile.green = env->tmp.tile.green;
	obj->tile.blue = env->tmp.tile.blue;
	obj->tile.w = env->tmp.tile.w;
	obj->ref = env->tmp.ref;
	obj->next = NULL;
	obj->prev = env->tmp_obj;
	return (obj);
}

t_light	*ft_fill_light(t_env *env)
{
	t_light	*light;

	light = NULL;
	if ((light = (t_light *)malloc(sizeof(t_light))) == NULL)
		ft_error();
	light->type = env->parse.type_light;
	light->pos.x = env->tmp.pos.x;
	light->pos.y = env->tmp.pos.y;
	light->pos.z = env->tmp.pos.z;
	light->dir.x = env->tmp.angles.x;
	light->dir.y = env->tmp.angles.y;
	light->dir.z = env->tmp.angles.z;
	light->color.red = env->tmp.color.red;
	light->color.green = env->tmp.color.green;
	light->color.blue = env->tmp.color.blue;
	light->next = NULL;
	light->prev = env->tmp_light;
	return (light);
}
