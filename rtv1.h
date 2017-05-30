/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:55:16 by marnaud           #+#    #+#             */
/*   Updated: 2017/05/16 20:24:03 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <SDL2/SDL.h>
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
    t_vct3i origin;
    t_vct3i	vct_normal;
    t_vct3i vct_directeur;
    int		rayon;
}               t_figure;

#endif
