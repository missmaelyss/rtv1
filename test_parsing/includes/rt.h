/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:00:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/01 14:30:17 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <get_next_line.h>
//# include <SDL.h>

enum {SPHERE, PLANE, CYL, CONE};
enum {OBJ = 1, LIGHT = 2, CAM = 3};

typedef struct		s_cam
{
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				dir_x;
	int				dir_y;
	int				dir_z;
}					t_cam;

typedef struct		s_tmp
{
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				radius;
	int				dir_x;
	int				dir_y;
	int				dir_z;
	int				red;
	int				green;
	int				blue;
}					t_tmp;

typedef struct		s_obj
{
	struct s_obj	*next;
	struct s_obj	*prev;
	int				type;
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				radius;
	int				dir_x;
	int				dir_y;
	int				dir_z;
	int				red;
	int				green;
	int				blue;
}					t_obj;

typedef struct		s_light
{
	struct s_light	*next;
	struct s_light	*prev;
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				dir_x;
	int				dir_y;
	int				dir_z;
}					t_light;

typedef struct		s_check
{
	int				position;
	int				direction;
	int				color;
	int				radius;
}					t_check;

typedef struct		s_parse
{
	int				fd;
	int				tablen;
	char			*line;
	char			**split;
	int				type;
	int				type_obj;
	int				objects;
	int				cam;
	int				lights;
}					t_parse;

/*typedef struct		s_sdl
{
	SDL_window		*win;
	SDL_Renderer	*rend;
}					t_sdl;*/

typedef struct	s_env
{
	t_parse			parse;
	//t_sdl			sdl;
	t_obj			*obj;
	t_light			*light;
	t_cam			cam;
	t_check			check;
}					t_env;

void				ft_parse(t_env *env, char *av);
void				ft_check_types(t_env *env);
void				ft_fill_cam(t_env *env);
void				ft_pos_cam(t_env *env, int i);
void				ft_error(void);
void				ft_error_file(void);
void				ft_error_sdl(void);
void				ft_init_env(t_env *env);
void				ft_check_objects(t_env *env);
void				ft_check_obj_types(t_env *env);
void				ft_parse_sphere(t_env *env);
void				ft_parse_color(t_env *env, int i);
void				ft_parse_position(t_env *env, int i);

#endif
