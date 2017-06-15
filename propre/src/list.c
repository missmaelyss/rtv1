/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:08:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 16:23:19 by ele-cren         ###   ########.fr       */
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
	obj->next = NULL;
	obj->prev = env->tmp_obj;
	return (obj);
}
