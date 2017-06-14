/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:00:36 by ele-cren          #+#    #+#             */
/*   Updated: 2017/06/14 16:35:23 by ele-cren         ###   ########.fr       */
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
# include <SDL.h>
# define WIDTH 640
# define HEIGHT 480
# define VIEWPLANED 1
# define VIEWPLANEW 0.64
# define VIEWPLANEH 0.48
# define F 1
# define XINDENT VIEWPLANEW / (double)WIDTH
# define YINDENT VIEWPLANEH / (double)HEIGHT

enum {SPHERE = 1, PLANE = 2, CYL = 3, CONE = 4};
enum {OBJ = 1, LIGHT = 2, CAM = 3};

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_calc
{
	int				color;
	double			a;
	double			b;
	double			c;
	double			solution;
	double			delta;
}					t_calc;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_cam
{
	t_vect			pos;
	t_vect			dir;
	t_vect			pixel;
	t_vect			view_plane;
	t_vect			up;
	t_vect			right;
}					t_cam;

typedef struct		s_obj
{
	struct s_obj	*next;
	struct s_obj	*prev;
	int				type;
	int				radius;
	t_vect			pos;
	t_vect			dir;
	t_color			color;
	int				angle;
}					t_obj;

typedef struct		s_tmp
{
	t_vect			pos;
	t_vect			dir;
	int				radius;
	t_color			color;
	int				angle;
	double			solution;
	t_obj			*current;
}					t_tmp;

typedef struct		s_light
{
	t_vect			pos;
	t_vect			dir;
}					t_light;

typedef struct		s_check
{
	int				position;
	int				direction;
	int				color;
	int				radius;
	int				angle;
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

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_PixelFormat	*format;
	int				keep;
	SDL_Event		event;
	SDL_Rect		pos;
}					t_sdl;

typedef struct	s_env
{
	t_parse			parse;
	t_sdl			sdl;
	t_obj			*obj;
	t_obj			*tmp_obj;
	t_light			light;
	//t_light			*tmp_light;
	t_cam			cam;
	t_check			check;
	t_tmp			tmp;
	t_calc			calc;
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
void				ft_parse_objects(t_env *env);
void				ft_parse_color(t_env *env, int i);
void				ft_parse_position(t_env *env, int i);
void				ft_parse_direction(t_env *env, int i);
void				ft_init_tmp(t_env *env);
void				ft_init_check(t_env *env);
t_obj				*ft_fill_obj(t_env *env);
void				ft_end_obj(t_env *env);
void				ft_fill_lights(t_env *env);
void				ft_init_sdl(t_env *env);
double				ft_scalar(t_vect vec1, t_vect vec2);
t_vect				ft_vect_op(t_vect vec1, char c, t_vect vec2);
t_vect				ft_vect_op2(double tmp, char c, t_vect vec);
void				ft_browse_pixels(t_env *env);
void				ft_browse_list(t_env *env);
void				ft_calc_sphere(t_env *env);
void				ft_init_start(t_env *env);

#endif
