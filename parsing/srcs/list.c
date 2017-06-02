/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:08:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/02 15:35:53 by ele-cren         ###   ########.fr       */
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
	obj->pos_x = env->tmp.pos_x;
	obj->pos_y = env->tmp.pos_y;
	obj->pos_z = env->tmp.pos_z;
	obj->dir_x = env->tmp.dir_x;
	obj->dir_y = env->tmp.dir_y;
	obj->dir_z = env->tmp.dir_z;
	obj->red = env->tmp.red;
	obj->green = env->tmp.green;
	obj->blue = env->tmp.blue;
	obj->next = NULL;
	obj->prev = env->tmp_obj;
	return (obj);
}
