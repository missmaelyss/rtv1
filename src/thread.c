/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:47:38 by gauffret          #+#    #+#             */
/*   Updated: 2017/07/27 18:31:43 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*static void	ft_init_texture(t_env *env)
{
			env->texture[0] = SDL_LoadBMP("img/moon.bmp");
			env->texture[1] = SDL_LoadBMP("img/soleil.bmp");
			env->texture[2] = SDL_LoadBMP("img/damier.bmp");
}

static void	ft_destroy_texture(t_env *env)
{
	SDL_FreeSurface(env->texture[0]);
	SDL_FreeSurface(env->texture[1]);
	SDL_FreeSurface(env->texture[2]);
}
*/
t_env		*ft_init_browse_pixels(t_env *env)
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

int			thread(void *envt)
{
	t_env		*env;

	env = (t_env *)envt;
	env->sdl.pos.y = env->thread.y_start;
	while (++env->sdl.pos.y < env->thread.y_end)
	{
		env->sdl.pos.x = env->thread.x_start;
		while (++env->sdl.pos.x < env->thread.x_end)
		{
			ft_init_pixel(env);
			ft_browse_list(env, env->cam.pixel, env->cam.pos, 0);
			if (env->tmp.solution >= 0)
			{
				env->tmp.ray_pos = env->cam.pos;
				env->tmp.ray_dir = env->cam.pixel;
				env->tmp.color = ft_chose_color(env);
				if (env->tmp.current->type == SPHERE)
				//		ft_refraction(env);	
						ft_reflexion(env);
				env->sdl.pixels[env->sdl.pos.x + (env->sdl.pos.y * WIDTHR)] =\
				SDL_MapRGBA(env->sdl.format, env->tmp.color.red, env->tmp.color.green, env->tmp.color.blue, 255);
			}
		}
	}
	env->thread.finished = 1;
	return (1);
}

void		init_limits(t_env *env)
{
	env->thread.y_start = ((env->thread.id == 0 || env->thread.id == 1) \
							? (-1) : (HEIGHT / 2 - 2));
	env->thread.y_end = ((env->thread.id == 0 || env->thread.id == 1) \
							? ((HEIGHT / 2) + 1) : (HEIGHT));
	env->thread.x_start = ((env->thread.id == 0 || env->thread.id == 2) \
							? (-1) : ((WIDTHR / 2) - 2));
	env->thread.x_end = ((env->thread.id == 0 || env->thread.id == 2) \
							? ((WIDTHR / 2) + 1) : (WIDTHR));
}

void	ft_browse_pixels(t_env *env)
{
	t_env	*e[4];
	int		i;

	i = -1;
	env = ft_init_browse_pixels(env);
	while (++i < 4)
	{
		e[i] = dup_struct(env, i);
		init_limits(e[i]);
	}
	env->thread.t[0] = SDL_CreateThread(thread, "thread1", e[0]);
	env->thread.t[1] = SDL_CreateThread(thread, "thread2", e[1]);
	env->thread.t[2] = SDL_CreateThread(thread, "thread3", e[2]);
	env->thread.t[3] = SDL_CreateThread(thread, "thread4", e[3]);
	SDL_WaitThread(env->thread.t[0], &e[0]->thread.finished);
	SDL_WaitThread(env->thread.t[1], &e[1]->thread.finished);
	SDL_WaitThread(env->thread.t[2], &e[2]->thread.finished);
	SDL_WaitThread(env->thread.t[3], &e[3]->thread.finished);
	i = -1;
	while (++i < 4)
		thread_suppr_dup(e[i]);
	SDL_UnlockTexture(env->sdl.draw);
}
