/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:08 by marnaud           #+#    #+#             */
/*   Updated: 2017/07/27 18:26:39 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

Uint32	obtenir_pixel(SDL_Surface *surface, int x, int y)
{
	int		nb_octet_pixel;
	Uint8	*p;

	nb_octet_pixel = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * nb_octet_pixel;
	if (surface == NULL)
		return (0);
	if (nb_octet_pixel == 1)
		return (*p);
	else if (nb_octet_pixel == 2)
		return (*(Uint16 *)p);
	else if (nb_octet_pixel == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (nb_octet_pixel == 4)
		return (*(Uint32 *)p);
	else
		return (0);
}

void	first_point(t_env *env, int *s, int *t)
{
	t_vect      point;
    SDL_Surface *texture;

    texture = env->texture[0];
	point.x = env->tmp.ray_pos.x - env->tmp.current->pos.x;
	point.y = env->tmp.ray_pos.y - env->tmp.current->pos.y;
	point.z = env->tmp.ray_pos.z - env->tmp.current->pos.z;
	point = (point.x != 1 && point.x != -1) ? \
			ft_vect_rot(point, -env->obj->angles.x, 3) : \
			ft_vect_rot(point, -env->obj->angles.x, 1);
	point = ft_vect_rot(point, -env->tmp.current->angles.y, 2);
	point = ft_vect_rot(point, -env->tmp.current->angles.z, 1);
		if (env->tmp.current->type == 2)
	{
		if (point.x < 0)
			point.x += texture->w * ceil(-point.x / texture->w);
		if (point.x > texture->w)
			point.x -= texture->w * floor(point.x / texture->w);
		*s = point.x;
		if (point.y < 0)
			point.y += texture->h * ceil(point.y / texture->h);
		if (point.y > texture->h)
			point.y -= texture->h * floor(point.y / texture->h);
		*t = point.y;
}
	else
	{
		if (env->tmp.current->type == 4)
		{
			if (point.y < 0)
				*s = floor(((point.x / (tan(env->tmp.current->angle) * point.z) + 1) / 2 ) * (texture->w / 2));
			else
				*s = floor(((-point.x / (tan(env->tmp.current->angle) * point.z) + 1) / 2 ) * (texture->w / 2)) + texture->w / 2;
		}
		else
		{
			if (point.y < 0)
				*s = floor(((point.x / env->tmp.current->radius + 1) / 2 ) * (texture->w / 2));
			else
				*s = floor(((-point.x / env->tmp.current->radius + 1) / 2 ) * (texture->w / 2)) + texture->w / 2;
		}
		if (env->tmp.current->type == 1)	
			*t = floor(((-point.z / env->tmp.current->radius + 1) / 2 ) * texture->h);
		else
		{
			if (point.z < 0)
				point.z += texture->h * ceil(-point.z / texture->h);
			if (point.z > texture->h)
				point.z -= texture->h * floor(point.z / texture->h);
			*t = point.z;
		}
	}
if (*t > texture->h || *t < -texture->h)
			*t = (*t < 0) ? -texture->h : texture->h;
		if (*s > texture->w || *s < -texture->w)
			*s = (*s < 0) ? -texture->w : texture->w;
}

t_color	ft_texture(t_env *env)
{
	int		s;
    int		t;
    Uint8   tmp[3];
	t_color color;

	env->tmp.ray_pos = env->light->solution_point;
	first_point(env, &s, &t);
    SDL_GetRGB(obtenir_pixel(env->texture[0], s, t) ,\
               env->texture[0]->format, &tmp[0], &tmp[1], &tmp[2]);
    color.red = (int)tmp[0];
    color.green = (int)tmp[1];
    color.blue = (int)tmp[2];
    return (color);
}
