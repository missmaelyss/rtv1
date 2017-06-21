/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:51:06 by marnaud           #+#    #+#             */
/*   Updated: 2017/06/19 14:34:09 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static	void	ft_clear_old_color(t_env *env, SDL_Color c[5])
{
	int n;

	SDL_GetRGBA(env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)],\
		env->sdl.format, &c[0].r, &c[0].g, &c[0].b, &c[0].a);
	n = 1;
	while (n < 5)
	{
		c[n].r = 0;
		c[n].g = 0;
		c[n].b = 0;
		c[n].a = 0;
		n++;
	}
}

static	int	ft_file_old_color(t_env *env, SDL_Color c[5])
{
	int n;

	n = 1;
		if (env->sdl.pos.x != 0)
	{
		SDL_GetRGBA(env->sdl.pixels[env->sdl.pos.x - 1 + (env->sdl.pos.y * WIDTH)],\
		env->sdl.format, &c[n].r, &c[n].g, &c[n].b, &c[n].a);
		n++;
	}
	if (env->sdl.pos.y != 0)
	{
		SDL_GetRGBA(env->sdl.pixels[env->sdl.pos.x + ((env->sdl.pos.y - 1) * WIDTH)],\
		env->sdl.format, &c[n].r, &c[n].g, &c[n].b, &c[n].a);
		n++;
	}
	if (env->sdl.pos.x != WIDTH - 1)
	{
		SDL_GetRGBA(env->sdl.pixels[env->sdl.pos.x + 1 + (env->sdl.pos.y * WIDTH)],\
		env->sdl.format, &c[n].r, &c[n].g, &c[n].b, &c[n].a);
		n++;
	}
	if (env->sdl.pos.y != HEIGHT - 1)
	{
		SDL_GetRGBA(env->sdl.pixels[env->sdl.pos.x + ((env->sdl.pos.y + 1) * WIDTH)],\
		env->sdl.format, &c[n].r, &c[n].g, &c[n].b, &c[n].a);
		n++;
	}	
	return (n - 1);
}

static	SDL_Color	ft_new_color(SDL_Color old_color[5], int n)
{
	SDL_Color tmp;

	tmp.r = (old_color[0].r * 1 + old_color[1].r + old_color[2].r + old_color[3].r + old_color[4].r) / (1 + n);
	tmp.g = (old_color[0].g * 1 + old_color[1].g + old_color[2].g + old_color[3].g + old_color[4].g) / (1 + n);
	tmp.b = (old_color[0].b * 1 + old_color[1].b + old_color[2].b + old_color[3].b + old_color[4].b) / (1 + n);
	return (tmp);
}

void	ft_antiali(t_env	*env)
{
	SDL_Texture	*tmp;
	SDL_Color	old_color[5];
	SDL_Color	new_color;
	int			n;
	Uint32		*pixels;

	if ((tmp = SDL_CreateTexture(env->sdl.rend, \
					SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, \
					WIDTH, HEIGHT)) == NULL)
		ft_error_sdl();
	SDL_LockTexture(tmp, NULL, &env->sdl.tmp, &env->sdl.pitch);
	pixels = env->sdl.tmp;
	env->sdl.pos.y = 0;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < WIDTH)
		{
			ft_clear_old_color(env, old_color);
			n = ft_file_old_color(env, old_color);
			new_color = ft_new_color(old_color, n);
			pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, new_color.r, new_color.g, new_color.b, 255);
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(tmp);
	env->sdl.draw = tmp;
}
