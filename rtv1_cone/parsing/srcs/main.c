/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:42:29 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/02 17:18:04 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		main(int ac, char **av)
{
	t_env	env;

	ft_parse(&env, av[1]);
	printf("cam dir_x %d\n", env.cam.dir_x);
	printf("sphere red %d\n", env.obj->red);
	printf("cyl red %d\n", env.obj->next->red);
	printf("radius sphere %d\n", env.obj->radius);
	printf("cyl dir_z %d\n", env.obj->next->dir_z);
	printf("light pos_x %d\n", env.light.pos_x);
	return (0);
}
