/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ev_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:55:45 by ele-cren          #+#    #+#             */
/*   Updated: 2017/07/19 17:35:58 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_ev_tex_rlb(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT || \
			env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (env->set.select == 2 || env->set.select == 3 || \
				env->set.select == 5 || env->set.select == 6 || \
				env->set.select == 8 || env->set.select == 9 || \
				env->set.select == 11 || env->set.select == 12)
			env->set.select = (env->set.select == 2 || env->set.select == 5 ||\
					env->set.select == 8 || env->set.select == 11) ? \
							  env->set.select + 1 : env->set.select - 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->set.select = 1;
		env->set.tab = ATTRIBUTES;
		env->set.inc = 1;
	}
}

void	ft_ev_tex_du(t_env *env)
{
	static int	test = 0;

	if (env->sdl.event.key.keysym.sym == SDLK_DOWN)
	{
		if (env->set.select == 14)
			env->set.select = (test == 1) ? 2 : 3;
		else if (env->set.select == 11 || env->set.select == 12)
		{
			test = (env->set.select == 11) ? 1 : 2;
			env->set.select = 14;
		}
		else
			env->set.select += 3;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_UP)
	{
		if (env->set.select == 2 || env->set.select == 3)
			test = (env->set.select == 2) ? 1 : 2;
		if (env->set.select == 2 || env->set.select == 3)
			env->set.select = 14;
		else if (env->set.select == 14)
		   env->set.select = (test == 1) ? 11 : 12;
		else
			env->set.select -= 3;	
	}
}

/*void	ft_ev_tex_return1(t_env *env)
{

}*/
