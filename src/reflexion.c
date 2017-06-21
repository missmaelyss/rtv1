/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:28:59 by marnaud           #+#    #+#             */
/*   Updated: 2017/06/21 14:05:41 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_new_color(t_env *env, t_obj *tmp)
{
	double	i;
	/*env->tmp.color.red = (env->tmp.current->color.red > tmp->color.red) ?
	(env->tmp.current->color.red / 2) + tmp->color.red :
	- (env->tmp.current->color.red / 2) + tmp->color.red;
	env->tmp.color.green = (env->tmp.current->color.green > tmp->color.green) ?
	(env->tmp.current->color.green / 2) + tmp->color.green :
	- (env->tmp.current->color.green / 2) + tmp->color.green;
	env->tmp.color.blue = (env->tmp.current->color.blue > tmp->color.blue) ?
	(env->tmp.current->color.blue / 2) + tmp->color.blue :
	- (env->tmp.current->color.blue / 2) + tmp->color.blue;
*/

	i = (env->tmp.solution < 0) ? 2 : 1 + (env->tmp.solution / 100) * 1;
	env->tmp.color.red = (tmp->color.red + env->tmp.current->color.red * i) / (1 + i);
	env->tmp.color.green = (tmp->color.green + env->tmp.current->color.green * i) / (1 + i);
	env->tmp.color.blue = (tmp->color.blue + env->tmp.current->color.blue * i) / (1 + i);
}

void	ft_reflexion(t_env *env)
{
	int		i;
	t_obj	*tmp;

	i = 0;
	tmp = env->tmp.current;
	env->tmp.ray_pos.x = env->cam.pos.x + env->cam.pixel.x * env->tmp.solution;
	env->tmp.ray_pos.y = env->cam.pos.y + env->cam.pixel.y * env->tmp.solution;
	env->tmp.ray_pos.z = env->cam.pos.z + env->cam.pixel.z * env->tmp.solution;
	ft_normal_vect(env, env->tmp.ray_pos);
	env->tmp.ray_dir = env->light->normal_vect;
	while (i < 1 && env->tmp.solution > 0)
	{
		if (i > 0)
		{
		printf("ui");
			env->tmp.ray_pos.x = env->tmp.ray_pos.x + env->tmp.ray_dir.x * env->tmp.solution;
			env->tmp.ray_pos.y = env->tmp.ray_pos.y + env->tmp.ray_dir.y * env->tmp.solution;
			env->tmp.ray_pos.z = env->tmp.ray_pos.z + env->tmp.ray_dir.z * env->tmp.solution;
			ft_normal_vect(env, env->tmp.ray_pos);
			env->tmp.ray_dir = ft_vect_op(env->tmp.ray_dir, '-', ft_vect_op2(2 * ft_scalar(\
				env->light->normal_vect, env->tmp.ray_dir), '*', env->light->normal_vect));
		}
		env->tmp.solution = 0;
		ft_browse_list(env, env->tmp.ray_dir, env->tmp.ray_pos);
		i++;
	}
	ft_new_color(env, tmp);
	//ft_light(env, ray_dir, ray_pos);
}
