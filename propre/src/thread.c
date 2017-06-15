/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:58:47 by ghubert           #+#    #+#             */
/*   Updated: 2017/06/15 10:55:19 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		thread_1(void *env_1)
{
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	env->sdl.pos.y = 0;
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	while (env->sdl.pos.y < (HEIGHT / 2))
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < (WIDTH / 2))
		{
			ft_init_pixel(env);
			ft_browse_list(env);
			if (env->calc.solution >= 0)
			{
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red, \
				env->tmp.current->color.green, env->tmp.current->color.blue, \
				255);;
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

int		thread_2(void *env_1)
{
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	env->sdl.pos.y = 0;
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	while (env->sdl.pos.y < (HEIGHT / 2))
	{
		env->sdl.pos.x = WIDTH / 2;
		while (env->sdl.pos.x < WIDTH)
		{
			ft_init_pixel(env);
			ft_browse_list(env);
			if (env->calc.solution >= 0)
			{
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red, \
				env->tmp.current->color.green, env->tmp.current->color.blue, \
				255);;
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

int		thread_3(void *env_1)
{
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	env->sdl.pos.y = HEIGHT / 2;
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = 0;
		while (env->sdl.pos.x < (WIDTH / 2))
		{
			ft_init_pixel(env);
			ft_browse_list(env);
			if (env->calc.solution >= 0)
			{
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red, \
				env->tmp.current->color.green, env->tmp.current->color.blue, \
				255);;
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

int		thread_4(void *env_1)
{
	t_env *env;

	env = (t_env *)env_1;
	ft_init_start(env);
	env->sdl.pos.y = HEIGHT / 2;
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	env->sdl.pixels = env->sdl.tmp;
	while (env->sdl.pos.y < HEIGHT)
	{
		env->sdl.pos.x = WIDTH / 2;
		while (env->sdl.pos.x < WIDTH)
		{
			ft_init_pixel(env);
			ft_browse_list(env);
			if (env->calc.solution >= 0)
			{
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTH)] = \
				SDL_MapRGBA(env->sdl.format, env->tmp.current->color.red, \
				env->tmp.current->color.green, env->tmp.current->color.blue, \
				255);;
			}
			env->sdl.pos.x++;
		}
		env->sdl.pos.y++;
	}
	SDL_UnlockTexture(env->sdl.draw);
	return (0);
}

void	ft_thread(t_env *env)
{
	int ret;

	ret = 0;
	env->thread.t_1 = NULL;
	env->thread.t_2 = NULL;
	env->thread.t_3 = NULL;
	env->thread.t_4 = NULL;
	env->thread.t_1 = SDL_CreateThread(thread_1, "T1", (void *)env);
	SDL_Delay(175);
	env->thread.t_2 = SDL_CreateThread(thread_2, "T2", (void *)env);
	SDL_Delay(175);
	env->thread.t_3 = SDL_CreateThread(thread_3, "T3", (void *)env);
	SDL_Delay(175);
	env->thread.t_4 = SDL_CreateThread(thread_4, "T4", (void *)env);
	SDL_Delay(175);
	SDL_WaitThread(env->thread.t_1, &ret);
	SDL_WaitThread(env->thread.t_2, &ret);
	SDL_WaitThread(env->thread.t_3, &ret);
	SDL_WaitThread(env->thread.t_4, &ret);
}
