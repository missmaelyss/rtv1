/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:02:08 by ele-cren          #+#    #+#             */
/*   Updated: 2017/01/31 13:06:35 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	return (nb * ft_pow(nb, pow - 1));
}
