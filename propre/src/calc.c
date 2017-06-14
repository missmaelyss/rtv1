/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:45:14 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/06 15:12:32 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	ft_scalar(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec	ft_vect_op(t_vec vec1, char c, t_vec vec2)
{
	t_vec	res;

	if (c == '-')
	{
		res.x = vec1.x - vec2.x;
		res.y = vec1.y - vec2.y;
		res.z = vec1.z - vec2.z;
	}
	else if (c == '+')
	{
		res.x = vec1.x + vec2.x;
		res.y = vec1.y + vec2.y;
		res.z = vec1.z + vec2.z;
	}
	return (res);
}

t_vec	ft_vect_op2(double tmp, char c, t_vec vec)
{
	t_vec	res;

	if (c == '*')
	{
		res.x = vec.x * tmp;
		res.y = vec.y * tmp;
		res.z = vec.z * tmp;
	}
	return (res);
}
