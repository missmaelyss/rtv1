/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:47:38 by gauffret          #+#    #+#             */
/*   Updated: 2017/07/25 21:47:53 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_env	*ft_init_browse_pixels(t_env *env)
{
	ft_init_draw(env);
	ft_init_start(env);
	ft_calc_angles(env);
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.draw);
	SDL_RenderClear(env->sdl.rend);
	SDL_SetRenderTarget(env->sdl.rend, NULL);
	SDL_LockTexture(env->sdl.draw, NULL, &env->sdl.tmp, &env->sdl.pitch);
	SDL_SetRenderTarget(env->sdl.rend, env->sdl.draw);
	env->sdl.pixels = env->sdl.tmp;
	return (env);
}

int	thread1(void *envt)
{
	t_color	color;
	t_env	*env;
	int		lock;
	int x;
	int y;

	env = (t_env *)envt;
	y = 0;
	lock = 1;
	while (y < (HEIGHT / 2) + 1)
	{
		x = 0;
		while (x < (WIDTHR / 2) + 1)
		{
			env->sdl.pos.x = x;
			env->sdl.pos.y = y;
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{
				color = ft_chose_color(env);
			//	ft_option_visu(env);
				env->sdl.pixels[x + (y * WIDTHR)] = SDL_MapRGBA(env->\
				sdl.format, color.red, color.green, color.blue, 255);
			}
			lock = 1;
			x++;
		}
		y++;
	}
	env->thread.finished = 1;
	return (1);
}

int	thread2(void *envt)
{
	t_color	color;
	t_env	*env;
	int		lock;
	int x;
	int y;

	env = (t_env *)envt;
	y = 0;
	lock = 1;
	while (y < (HEIGHT / 2) + 1)
	{
		x = (WIDTHR / 2) - 1;
		while (x < WIDTHR)
		{
			env->sdl.pos.x = x;
			env->sdl.pos.y = y;
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{
				color = ft_chose_color(env);
			//	ft_option_visu(env);
				env->sdl.pixels[x + (y * WIDTHR)] = SDL_MapRGBA(env->\
				sdl.format, color.red, color.green, color.blue, 255);
			}
			lock = 1;
			x++;
		}
		y++;
	}
	env->thread.finished = 1;
	return (1);
}

int	thread3(void *envt)
{
	t_color	color;
	t_env	*env;
	int		lock;
	int x;
	int y;

	env = (t_env *)envt;
	y = (HEIGHT / 2) - 1;
	lock = 1;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < (WIDTHR / 2) + 1)
		{
			env->sdl.pos.x = x;
			env->sdl.pos.y = y;
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{	
				color = ft_chose_color(env);
			//	ft_option_visu(env);
				env->sdl.pixels[x + (y * WIDTHR)] = SDL_MapRGBA(env->\
				sdl.format, color.red, color.green, color.blue, 255);
			}
			lock = 1;
			x++;
		}
		y++;
	}
	env->thread.finished = 1;
	return (1);
}

int	thread4(void *envt)
{
	t_color	color;
	t_env	*env;
	int		lock;
	int x;
	int y;

	env = (t_env *)envt;
	y = HEIGHT / 2 - 1;
	lock = 1;
	while (y < HEIGHT)
	{
		x = WIDTHR / 2 - 1;
		while (x < WIDTHR)
		{
			env->sdl.pos.x = x;
			env->sdl.pos.y = y;
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos);
			if (env->tmp.solution >= 0)
			{	
				color = ft_chose_color(env);
			//	ft_option_visu(env);
				env->sdl.pixels[x + (y * WIDTHR)] = SDL_MapRGBA(env->\
				sdl.format, color.red, color.green, color.blue, 255);
			}
			lock = 1;
			x++;
		}
		y++;
	}
	env->thread.finished = 1;
	return (1);
}

void	ft_browse_pixels(t_env *env)
{
	t_env	*envt1;
	t_env	*envt2;
	t_env	*envt3;
	t_env	*envt4;
	
	env = ft_init_browse_pixels(env);
	envt1 = dup_struct(env, 0);
	envt2 = dup_struct(env, 1);
	envt3 = dup_struct(env, 2);
	envt4 = dup_struct(env, 3);
	env->thread.t_1 = SDL_CreateThread(thread1, "thread1", envt1);
	env->thread.t_2 = SDL_CreateThread(thread2, "thread2", envt2);
	env->thread.t_3 = SDL_CreateThread(thread3, "thread3", envt3);
	env->thread.t_4 = SDL_CreateThread(thread4, "thread4", envt4);
	SDL_WaitThread(env->thread.t_1, &envt1->thread.finished);
	SDL_WaitThread(env->thread.t_2, &envt2->thread.finished);
	SDL_WaitThread(env->thread.t_3, &envt3->thread.finished);
	SDL_WaitThread(env->thread.t_4, &envt4->thread.finished);
	SDL_UnlockTexture(env->sdl.draw);
}
