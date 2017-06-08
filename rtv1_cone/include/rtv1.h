/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:55:16 by marnaud           #+#    #+#             */
/*   Updated: 2017/06/08 11:26:25 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <SDL.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_vct2i
{
    int x;
    int y;
}               t_vct2i;

typedef struct s_vct3i
{
    int x;
    int y;
    int z;
}               t_vct3i;

typedef struct s_vct3d
{
    double x;
    double y;
    double z;
}               t_vct3d;

typedef struct s_figure
{
    int    name;
    t_vct3d origin;
    t_vct3d	vct_normal;
    t_vct3d vct_directeur;
	t_vct3d	directeur;
	t_vct3d	base;
	t_vct3d	cone;
    int		rayon;
}               t_figure;

#endif
