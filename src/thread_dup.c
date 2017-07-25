/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:47:45 by gauffret          #+#    #+#             */
/*   Updated: 2017/07/25 15:24:37 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color	dup_color(t_color src)
{
	t_color	dest;

	dest.red = src.red;
	dest.green = src.green;
	dest.blue = src.blue;
	dest.w = src.w;
	return (dest);
}

t_vect	dup_vect(t_vect src)
{
	t_vect	dest;

	dest.x = src.x;
	dest.y = src.y;
	dest.z = src.z;
	dest.h = src.h;
	return (dest);
}

t_light	*dup_light(t_light *src) //prev next a verifier
{
	t_light	*start;
	t_light	*link_src;
	t_light	*link_dest;
	t_light	*new;

	start = NULL;
	new = NULL;
	link_src = src;
	while (link_src)
	{
		if ((new = (t_light *)malloc(sizeof(t_light))) == NULL)
			ft_error();
		if (link_dest)
			new->prev = link_dest;
		else
			new->prev = NULL;
		new->next = NULL;
		new->type = link_src->type;
		new->pos = dup_vect(link_src->pos);
		new->solution_point = dup_vect(link_src->solution_point);
		new->normal_vect = dup_vect(link_src->normal_vect);
		new->light_vect = dup_vect(link_src->light_vect);
		new->norme = link_src->norme;
		new->power = link_src->power;
		new->dir = dup_vect(link_src->dir);
		new->color = dup_color(link_src->color);
		if (!start)
		{
			start = new;
			link_dest = start;
		}
		else
		{
			link_dest->next = new;
			link_dest = link_dest->next;
		}
		link_src = link_src->next;
	}
	return (start);
}

t_calc	dup_calc(t_calc src)
{
	t_calc	dest;

	dest.color = src.color;
	dest.a = src.a;
	dest.b = src.b;
	dest.c = src.c;
	dest.solution = src.solution;
	dest.delta = src.delta;
	dest.delta_p = dup_vect(src.delta_p);
	return (dest);
}

t_obj	*dup_obj(t_obj *src, t_env *env) //prev next a verifier
{
	t_obj	*start;
	t_obj	*link_src;
	t_obj	*link_dest;
	t_obj	*new;

	link_src = NULL;
	link_src = src;
	start = NULL;
	new = NULL;
	//ft_putendl("debut obj");
	while (link_src && env->parse.objects > 0)
	{
		//ft_putendl("debut while obj");
		new = (t_obj *)malloc(sizeof(t_obj));
		if (link_dest)
			new->prev = link_dest;
		else
			new->prev = NULL;
		new->next = NULL;
		new->type = link_src->type;
		new->radius = link_src->radius;
		new->angles = dup_vect(link_src->angles);
		new->pos = dup_vect(link_src->pos);
		new->color = dup_color(link_src->color);
		new->angle = link_src->angle;
		new->dir = dup_vect(link_src->dir);
		new->tile = dup_color(link_src->tile);
		new->tex = link_src->tex;
		new->refra = src->refra;
		new->refle = src->refle;
		new->fin[0] = link_src->fin[0];
		new->fin[1] = link_src->fin[1];
		new->finished = link_src->finished;
		if (!start)
		{
			start = new;
			link_dest = start;
		}
		else
		{
			link_dest->next = new;
			link_dest = link_dest->next;
		}
		link_src = link_src->next;
		//ft_putendl("fin while obj");
	}
	//ft_putendl("fin obj");
	return (start);
}

t_tmp	dup_tmp(t_tmp src)
{
	t_tmp	tmp;

	tmp.radius = src.radius;
	tmp.type = src.type;
	tmp.id_o = src.id_o;
	tmp.angle = src.angle;
	tmp.solution = src.solution;
	tmp.i = src.i;
	tmp.darkness = src.darkness;
	tmp.power = src.power;
	tmp.tex = src.tex;
	tmp.refra = src.refra;
	tmp.refle = src.refle;
	tmp.fin[0] = src.fin[0];
	tmp.fin[1] = src.fin[1];
	tmp.finished = src.finished;
	tmp.current = src.current;//dup_obj(src.current);
	tmp.pos = dup_vect(src.pos);
	tmp.angle = src.angle;
	tmp.color = dup_color(src.color);
	tmp.tile = dup_color(src.tile);
	return(tmp);
}

t_cam	dup_cam(t_cam src)
{
	t_cam	cam;

	cam.pos = dup_vect(src.pos);
	cam.dir = dup_vect(src.dir);
	cam.pixel = dup_vect(src.pixel);
	cam.view_plane = dup_vect(src.view_plane);
	cam.up = dup_vect(src.up);
	cam.right = dup_vect(src.right);
	return (cam);
}

t_env	*dup_struct(t_env* src, int id)// dup minimun multithreading
{
	t_env	*dest;

	dest = (t_env *)malloc(sizeof(t_env));
	dest->sdl = src->sdl;
	dest->parse = src->parse;
	dest->check = src->check;
	dest->set = src->set;
	dest->sdl.format = src->sdl.format;
	dest->sdl.pixels = src->sdl.pixels;
	dest->sdl.tmp = src->sdl.tmp;
	dest->sdl.rend = src->sdl.rend;
	dest->sdl.pitch = src->sdl.pitch;
	dest->thread.id = id;
	dest->cam = dup_cam(src->cam);
	dest->tmp = dup_tmp(src->tmp);
	dest->calc = dup_calc(src->calc);
	dest->obj = NULL;
	dest->obj = dup_obj(src->obj, src);
	dest->tmp_obj = NULL;
	dest->light = NULL;
	dest->light = dup_light(src->light);
	dest->tmp_light = NULL;
	return (dest);
}
