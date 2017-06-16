/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawasche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:31:31 by mawasche          #+#    #+#             */
/*   Updated: 2017/06/16 18:26:16 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_shadow(t_env *env)
{
	void    (*ft_calc[4])(t_env*, t_vect ray_dir, t_vect ray_pos);
	t_obj   *lst;
	int		i;
    
	i = 0;
	ft_calc[0] = ft_calc_sphere;
	ft_calc[1] = ft_calc_plane;
	ft_calc[2] = ft_calc_cyl;
	ft_calc[3] = ft_calc_cone;
	lst = env->obj;
	env->tmp.darkness = 1;
	while (env->obj)
	{
		env->calc.solution = -1;
        //while (env->light)
        //{
            ft_calc[env->obj->type - 1](env, env->light->light_vect, env->light->solution_point);
            if (env->calc.solution >= 0 && env->tmp.i != i)
            {
                env->tmp.darkness -= 0.8;
                //break;
            }
           // if (!(env->light->next))
            //    break;
            //env->light = env->light->next;
        //}
        i++;
        env->obj = env->obj->next;
	}
    env->tmp.darkness = (env->tmp.darkness <= 0) ? 0.1 : env->tmp.darkness;
	env->obj = lst;
   // env->light = env->tmp_light;
}
