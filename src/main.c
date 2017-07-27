/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:42:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/26 14:45:33 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_main_wh(t_env *env)
{
	SDL_WaitEvent(&env->sdl.event);
	if (env->sdl.event.type == SDL_QUIT)
		env->sdl.keep = 0;
	if (env->sdl.event.type == SDL_KEYDOWN)
	{
		ft_event_cam_rlf(env);
		ft_event(env);
		ft_settings(env);
		ft_display(env);
		if (env->sdl.event.key.keysym.sym == SDLK_ESCAPE)
			env->sdl.keep = 0;
	}
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		ft_parse(&env, av[1]);
		ft_init_sdl(&env);
		ft_init_set(&env);
		ft_settings(&env);
		ft_browse_pixels(&env);
		ft_display(&env);
		while (env.sdl.keep)
			ft_main_wh(&env);
		ft_free(&env);
		SDL_DestroyRenderer(env.sdl.rend);
		SDL_DestroyWindow(env.sdl.win);
		SDL_Quit();
	}
	else
		ft_putendl("Usage : ./rt scene");
	return (0);
}
