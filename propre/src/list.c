/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:08:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/12 12:00:22 by ele-cren         ###   ########.fr       */
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
	obj->dir.x = env->tmp.dir.x;
	obj->dir.y = env->tmp.dir.y;
	obj->dir.z = env->tmp.dir.z;
	obj->color.red = env->tmp.color.red;
	obj->color.green = env->tmp.color.green;
	obj->color.blue = env->tmp.color.blue;
	obj->next = NULL;
	obj->prev = env->tmp_obj;
	return (obj);
}
