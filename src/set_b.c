/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:03:11 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 10:38:25 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_base_tab(t_env *env)
{
	if ((env->sdl.tset[TINTER] = SDL_CreateTexture(env->sdl.rend, \
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTHS, \
			HEIGHT)) == NULL)
		ft_error_sdl();
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.tset[TINTER]);
	env->sdl.tset[TIMG] = ft_img_to_tex(env, "img/attributes.bmp");
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TIMG], NULL, NULL);
	SDL_DestroyTexture(env->sdl.tset[TIMG]);
	if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 30)) == NULL)
		ft_error_sdl();
	ft_base_text(env);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
}

void	ft_base_text(t_env *env)
{
	int		i;
	int		max;
	char	*name;

	name = NULL;
	i = 0;
	max = (env->set.obj[3]->finished == 0) ? 11 : 17;
	if (max == 17)
		if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 25)) == NULL)
			ft_error_sdl();
	while (++i <= max)
	{
		name = (i == 1) ? ft_freestrjoin("Increment :  ", \
			ft_itoa(env->set.inc), 2) : name;
		name = (i == 2) ? ft_strdup("x2") : name;
		name = (i == 3) ? ft_strdup("/2") : name;
		name = (i == 4) ? ft_freestrjoin("Radius :  ", \
			ft_itoa(env->set.obj[3]->radius), 2) : name;
		name = (i == 5) ? ft_strdup("+") : name;
		name = (i == 6) ? ft_strdup("-") : name;
		ft_base_text2(env, &name, i, max);
		ft_strdel(&name);
	}
}

void	ft_base_text2(t_env *env, char **name, int i, int max)
{
	*name = (i == 7) ? ft_freestrjoin("Angle :  ", \
		ft_itoa(env->set.obj[3]->angle), 2) : *name;
	*name = (i == 8) ? ft_strdup("+") : *name;
	*name = (i == 9) ? ft_strdup("-") : *name;
	*name = (i == 10) ? ft_strdup("Object : ") : *name;
	if (i == 11)
	{
		*name = (env->set.obj[3]->finished == 0) ? \
			ft_strdup("Not Finished") : \
			ft_strdup("Finished");
	}
	if (max == 17)
	{
		*name = (i == 12) ? ft_freestrjoin("Min : ", \
			ft_itoa(env->set.obj[3]->fin[0]), 2) : *name;
		*name = (i == 13) ? ft_strdup("+") : *name;	
		*name = (i == 14) ? ft_strdup("-") : *name;
		*name = (i == 15) ? ft_freestrjoin("Max : ", \
			ft_itoa(env->set.obj[3]->fin[1]), 2) : *name;
		*name = (i == 16) ? ft_strdup("+") : *name;	
		*name = (i == 17) ? ft_strdup("-") : *name;
	}
	env->sdl.text = TTF_RenderText_Blended(env->sdl.font, *name, \
		env->set.color[(env->set.select == i) ? 1 : 0]);
	ft_copy_base_text(env, i, max);
}

void    ft_copy_base_text(t_env *env, int i, int max)
{
	if ((env->sdl.tset[TTEXT] = SDL_CreateTextureFromSurface(env->sdl.rend, \
				env->sdl.text)) == NULL)
		ft_error_sdl();
	SDL_QueryTexture(env->sdl.tset[TTEXT], NULL, NULL, &env->sdl.rset[DTEXT].w\
		, &env->sdl.rset[DTEXT].h);
	env->sdl.rset[DTEXT].x = WIDTHS / 2 - (env->sdl.rset[DTEXT].w / 2);
	if (i == 2 || i == 3 || i == 5 || i == 6 || i == 8 || i == 9 || i == 13 || \
			i == 14 || i == 16 || i == 17)
		env->sdl.rset[DTEXT].x = (i == 2 || i == 5 || i == 8 || i == 13 || i ==\
			16) ? env->sdl.rset[DTEXT].x - 20 : env->sdl.rset[DTEXT].x + 20;
	else if (i == 10 || i == 11)
	{
		if (max == 17)
			env->sdl.rset[DTEXT].x = (i == 10) ? env->sdl.rset[DTEXT].x - 45 : \
				env->sdl.rset[DTEXT].x + 45;
		else
			env->sdl.rset[DTEXT].x = (i == 10) ? env->sdl.rset[DTEXT].x - 62 : \
				env->sdl.rset[DTEXT].x + 62;
	}
	ft_copy_base_text2(env, i, max);
}

void	ft_copy_base_text2(t_env *env, int i, int max)
{
	env->sdl.rset[DTEXT].y = HEIGHT / 4 + env->set.pos;
	SDL_FreeSurface(env->sdl.text);
	SDL_RenderCopy(env->sdl.rend, env->sdl.tset[TTEXT], NULL, \
			&env->sdl.rset[DTEXT]);
	if ((i % 3 == 0 ) || i == 1 || i == 4 || i == 7 || i == 11 || i == 14)
		env->set.pos = (max == 17) ? env->set.pos + 30 : env->set.pos + 40;
	env->set.pos = ((i % 11 == 0 && max == 11) || (i % 17 == 0 && max == 17)) \
		? 0 : env->set.pos;
}
