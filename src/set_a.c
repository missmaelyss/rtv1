/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:13:30 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 11:03:44 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_attributes(t_env *env)
{
	if ((env->sdl.tset[TINTER] = SDL_CreateTexture(env->sdl.rend, \
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTHS, \
		HEIGHT)) == NULL)
		ft_error_sdl();
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.tset[TINTER]);
	if (env->set.p[1] == 0)
	{
		env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/attributesn.bmp");
		SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
		ft_at_text1(env);
	}
	else if (env->set.p[1] == 1)
	{
		env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/attributesp.bmp");
		SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
		ft_at_text2(env);
	}
	SDL_DestroyTexture(env->sdl.tset[TIMG]);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
}

void	ft_at_text1(t_env *env)
{
	int		i;
	char	*name;

	name = NULL;
	i = 1;
	while (i <= 6)
	{
		name = (i == 1) ? ft_strdup("Add") : name;
		name = (i == 2) ? ft_strdup("Delete") : name;
		name = (i == 3) ? ft_strdup("Position") : name;
		name = (i == 4) ? ft_strdup("Direction") : name;
		name = (i == 5) ? ft_strdup("Color") : name;
		name = (i == 6) ? ft_strdup("Base") : name;
		env->sdl.text = TTF_RenderText_Blended(env->sdl.font, name, \
			env->set.color[(env->set.select == i) ? 1 : 0]);
		ft_copy_text_at(env, i);
		ft_strdel(&name);
		i++;
	}
}

void	ft_at_text2(t_env *env)
{
	int		i;
	char	*name;

	name = NULL;
	i = 1;
	while (i <= 2)
	{
		name = (i == 1) ? ft_strdup("Effects") : name;
		name = (i == 2) ? ft_strdup("Textures") : name;
		env->sdl.text = TTF_RenderText_Blended(env->sdl.font, name, \
			env->set.color[(env->set.select == i) ? 1 : 0]);
		ft_copy_text_at(env, i);
		ft_strdel(&name);
		i++;
	}
}

void	ft_copy_text_at(t_env *env, int i)
{
	if ((env->sdl.tset[TTEXT] = SDL_CreateTextureFromSurface(env->sdl.rend, \
			env->sdl.text)) == NULL)
		ft_error_sdl();
	SDL_QueryTexture(env->sdl.tset[TTEXT], NULL, NULL, &env->sdl.rset[DTEXT].w\
		, &env->sdl.rset[DTEXT].h);
	env->sdl.rset[DTEXT].x = ((WIDTHS / 2) - (env->sdl.rset[DTEXT].w / 2));
	env->sdl.rset[DTEXT].y = HEIGHT / 4 + env->set.pos;
	SDL_FreeSurface(env->sdl.text);
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TTEXT], NULL, \
		&env->sdl.rset[DTEXT]);
	env->set.pos = (i == 6 || (i == 2 && env->set.p[1] == 1)) ? 0 : \
		env->set.pos + 50;
}
