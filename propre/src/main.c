/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:42:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/15 10:45:34 by ghubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		main(int ac, char **av)
{
	t_env	env;
	int		i;

	if (ac == 2)
	{
		i = 1;
		ft_parse(&env, av[1]);
		ft_init_sdl(&env);
		//ft_thread(&env);
		ft_display(&env);
		while (env.sdl.keep)
		{
			SDL_WaitEvent(&env.sdl.event);
			if (env.sdl.event.type == SDL_QUIT || \
								env.sdl.event.key.keysym.sym == SDLK_ESCAPE)
				env.sdl.keep = 0;
		}
		SDL_DestroyRenderer(env.sdl.rend);
		SDL_DestroyWindow(env.sdl.win);
		SDL_Quit();
	}
	else
		ft_putendl("Usage : ./rt scene");
	return (0);
}
