/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:50:54 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 10:50:23 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_tex_tab(t_env *env)
{
	if ((env->sdl.tset[TINTER] = SDL_CreateTexture(env->sdl.rend, \
				SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTHS, \
				HEIGHT)) == NULL)
		ft_error_sdl();
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.tset[TINTER]);
	env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/attributes.bmp");
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
	SDL_DestroyTexture(env->sdl.tset[TIMG]);
	if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 28)) == NULL)
		ft_error_sdl();
	ft_tex_text(env);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
}

void	ft_tex_text(t_env *env)
{
	int     i;
	char    *name;

	name = NULL;
	i = 1;
	while (i <= 14)
	{
		name = (i == 1) ? ft_freestrjoin("Increment :  ", \
			ft_itoa(env->set.inc), 2) : name;
		name = (i == 2) ? ft_strdup("x2") : name;
		name = (i == 3) ? ft_strdup("/2") : name;
		name = (i == 4) ? ft_freestrjoin("Red :  ", \
			ft_itoa(env->set.obj[3]->color.red), 2) : name;
		name = (i == 5) ? ft_strdup("+") : name;
		name = (i == 6) ? ft_strdup("-") : name;
		name = (i == 7) ? ft_freestrjoin("Green :  ", \
			ft_itoa(env->set.obj[3]->color.green), 2) : name;
		ft_tex_text2(env, i, &name);
		env->sdl.text = TTF_RenderText_Blended(env->sdl.font, name, \
			env->set.color[(env->set.select == i) ? 1 : 0]);
		ft_copy_tex_text(env, i);
		ft_strdel(&name);
		i++;
	}
}

void	ft_tex_text2(t_env *env, int i, char **name)
{
	*name = (i == 8) ? ft_strdup("+") : *name;
	*name = (i == 9) ? ft_strdup("-") : *name;
	*name = (i == 10) ? ft_freestrjoin("Blue :  ", \
		ft_itoa(env->set.obj[3]->color.blue), 2) : *name;
	*name = (i == 11) ? ft_strdup("+") : *name;
	*name = (i == 12) ? ft_strdup("-") : *name;
	*name = (i == 13) ? ft_strdup("Tiles : ") : *name;
	if (i == 14)
		*name = (env->set.obj[3]->tex == TILE) ? ft_strdup("On") : \
			ft_strdup("Off");
}

void	ft_copy_tex_text(t_env *env, int i)
{
	if ((env->sdl.tset[TTEXT] = SDL_CreateTextureFromSurface(env->sdl.rend, \
				env->sdl.text)) == NULL)
		ft_error_sdl();
	SDL_QueryTexture(env->sdl.tset[TTEXT], NULL, NULL, &env->sdl.rset[DTEXT].w\
		, &env->sdl.rset[DTEXT].h);
	env->sdl.rset[DTEXT].x = WIDTHS / 2 - (env->sdl.rset[DTEXT].w / 2);
	if (i == 2 || i == 3 || i == 5 || i == 6 || i == 8 || i == 9 || i == 11 || \
			i == 12 || i == 13 || i == 14)
		env->sdl.rset[DTEXT].x = (i == 2 || i == 5 || i == 8 || i == 11 || \
		i == 13) ? env->sdl.rset[DTEXT].x - 30 : env->sdl.rset[DTEXT].x + 30;
	else if (i == 13 || i == 14)
		env->sdl.rset[DTEXT].x = (i == 13) ? env->sdl.rset[DTEXT].x - 30 : \
			env->sdl.rset[DTEXT].x + 30;
	env->sdl.rset[DTEXT].y = HEIGHT / 4 + env->set.pos;
	SDL_FreeSurface(env->sdl.text);
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TTEXT], NULL, \
		&env->sdl.rset[DTEXT]);
	env->set.pos = (i % 3 == 0 || i == 1 || i == 4 || i == 7 || i == 10) ? \
		env->set.pos + 35 : env->set.pos;
	env->set.pos = (i % 14 == 0) ? 0 : env->set.pos;
}
