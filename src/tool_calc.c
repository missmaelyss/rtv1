/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:08:26 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/20 13:35:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vect	ft_calc_sol(t_env *env)
{
	t_vect	sol;

	sol.x = env->cam.pos.x + env->cam.pixel.x * env->tmp.solution;
	sol.y = env->cam.pos.y + env->cam.pixel.y * env->tmp.solution;
	sol.z = env->cam.pos.z + env->cam.pixel.z * env->tmp.solution;
	return (sol);
}
