/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:07:16 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/25 11:45:58 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ev_at_dubrl(t_env *env)
{
	int		max;

	max = (env->set.p[1] == 0) ? 6 : 2;
	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
		env->set.select = (env->set.select == max) ? 1 : env->set.select + 1;
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
		env->set.select = (env->set.select == 1) ? max : env->set.select - 1;
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		ft_init_set(env);
		env->set.tab = OBJECTS;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT && env->set.p[1] == 0)
	{
		env->set.p[1] += 1;
		env->set.select = 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_LEFT && env->set.p[1] == 1)
	{
		env->set.p[1] -= 1;
		env->set.select = 1;
	}
}

void	ft_ev_at_return1(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN)
	{
		if (env->set.p[1] == 0)
		{
			if (env->set.select == 1)
			{
				env->parse.objects++;
				ft_add_elem_obj(env);
				env->tmp.current = NULL;
				SDL_DestroyTexture(env->sdl.draw);
				ft_browse_pixels(env);
				ft_init_set(env);
				env->set.tab = OBJECTS;
			}
			else if (env->set.select == 2)
				ft_ev_at_return2(env);
			else if (env->set.select == 3 || env->set.select == 4 || \
					env->set.select == 5 || env->set.select == 6)
				ft_ev_at_return3(env);
		}
		ft_ev_at_return4(env);
	}
}

void	ft_ev_at_return2(t_env *env)
{
	env->parse.objects--;
	ft_stock_elem(env);
	ft_delete_elem_obj(env);
	ft_init_set(env);
	env->set.del = 1;
	SDL_DestroyTexture(env->sdl.draw);
	ft_browse_pixels(env);
	env->set.tab = OBJECTS;
	if (env->parse.objects == 0)
	{
		if ((env->sdl.font = TTF_OpenFont("fonts/bodoni.ttf", 50)) == NULL)
			ft_error_sdl();
		env->obj = NULL;
		env->set.tab = INTERFACE;
	}
}

void	ft_ev_at_return3(t_env *env)
{
	if (env->set.select == 3)
	{
		env->set.tab = POSTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 4)
	{
		env->set.tab = DIRTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 5)
	{
		env->set.tab = COLTAB;
		env->set.select = 2;
	}
	else if (env->set.select == 6)
	{
		env->set.tab = BASETAB;
		env->set.select = 2;
	}
}

void	ft_ev_at_return4(t_env *env)
{
	if (env->set.p[1] == 1)
	{
		if (env->set.select == 1)
		{
			env->set.tab = EFFTAB;
			env->set.select = 2;
		}
		else if (env->set.select == 2)
		{
			env->set.tab = TEXTAB;
			env->set.select = 2;
		}
	}
}
