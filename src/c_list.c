#include <rt.h>

void	ft_add_elem_obj(t_env *env)
{
	t_obj	*tmp;
	t_obj	*obj;

	tmp = env->set.obj[3];
	while (tmp->next)
		tmp = tmp->next;
	if ((obj = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	obj->type = env->set.obj[3]->type;;
	obj->radius = env->set.obj[3]->radius;
	obj->angle = env->set.obj[3]->angle;
	obj->pos.x = env->set.obj[3]->pos.x;
	obj->pos.y = env->set.obj[3]->pos.y;
	obj->pos.z = env->set.obj[3]->pos.z;
	obj->angles.x = env->set.obj[3]->angles.x;
	obj->angles.y = env->set.obj[3]->angles.y;
	obj->angles.z = env->set.obj[3]->angles.z;
	obj->angles.h = env->set.obj[3]->angles.h;
	obj->color.red = env->set.obj[3]->color.red;
	obj->color.green = env->set.obj[3]->color.green;
	obj->color.blue = env->set.obj[3]->color.blue;
	obj->tex = env->set.obj[3]->tex;
	obj->tile.red = env->set.obj[3]->tile.red;
	obj->tile.green = env->set.obj[3]->tile.green;
	obj->tile.blue =env->set.obj[3]->tile.blue;
	obj->tile.w = env->set.obj[3]->tile.w;
	obj->refle = env->set.obj[3]->refle;
	obj->refra = env->set.obj[3]->refra;
	obj->finished = env->set.obj[3]->finished;
	obj->fin[0] = env->set.obj[3]->fin[0];
	obj->fin[1] = env->set.obj[3]->fin[1];
	obj->next = NULL;
	obj->prev = tmp;
	tmp->next = obj;
}

void	ft_delete_elem_obj(t_env *env)
{
	t_obj	*start;
	t_obj	*tmp;
	int		i;

	tmp = NULL;
	start = env->obj;
	if (env->set.id_o == 1 && env->set.obj[3]->next == NULL)
	{
		free(env->obj);
		env->obj = NULL;
	}
	else if (env->set.obj[3]->next == NULL)
	{
		tmp = env->set.obj[3]->prev;
		tmp->next = NULL;
		free(env->set.obj[3]);
	}
	else if (env->set.id_o == 1)
	{
		tmp = env->obj;
		env->obj = env->obj->next;
		free(tmp);
	}
	else
	{
		i = 1;
		while (start && i < env->set.id_o)
		{
			if (i + 1 && i + 1 == env->set.id_o)
			{
				tmp = start->next;
				start->next = tmp->next;
				start->next->prev = start;
				free(tmp);
			}
			i++;
			start = start->next;
		}
	}
}

void	ft_stock_elem(t_env *env)
{
	env->parse.type_obj = env->set.obj[3]->type;
	env->tmp.pos.x = env->set.obj[3]->pos.x;
	env->tmp.pos.y = env->set.obj[3]->pos.y;
	env->tmp.pos.z = env->set.obj[3]->pos.z;
	env->tmp.angles.x = env->set.obj[3]->angles.x;
	env->tmp.angles.y = env->set.obj[3]->angles.y;
	env->tmp.angles.z = env->set.obj[3]->angles.z;
	env->tmp.angles.h = env->set.obj[3]->angles.h;
	env->tmp.color.red = env->set.obj[3]->color.red;
	env->tmp.color.green = env->set.obj[3]->color.green;
	env->tmp.color.blue = env->set.obj[3]->color.blue;
	env->tmp.tile.red = env->set.obj[3]->tile.red;
	env->tmp.tile.green = env->set.obj[3]->tile.green;
	env->tmp.tile.blue = env->set.obj[3]->tile.blue;
	env->tmp.tile.w = env->set.obj[3]->tile.w;
	env->tmp.tex = env->set.obj[3]->tex;
	env->tmp.refle = env->set.obj[3]->refle;
	env->tmp.refra = env->set.obj[3]->refra;
	env->tmp.angle = env->set.obj[3]->angle;
	env->tmp.radius = env->set.obj[3]->radius;
	env->tmp.finished = env->set.obj[3]->finished;
	env->tmp.fin[0] = env->set.obj[3]->fin[0];
	env->tmp.fin[1] = env->set.obj[3]->fin[1];
	env->tmp.id_o = env->set.id_o;
}

void	ft_undelete(t_env *env)
{
	int		i;
	t_obj		*start;
	t_obj		*new;

	start = NULL;
	new = NULL;
	if ((new = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		ft_error();
	new->type = env->parse.type_obj;
	new->pos.x = env->tmp.pos.x;
	new->pos.y = env->tmp.pos.y;
	new->pos.z = env->tmp.pos.z;
	new->angles.x = env->tmp.angles.x;
	new->angles.y = env->tmp.angles.y;
	new->angles.z = env->tmp.angles.z;
	new->angles.h = env->tmp.angles.h;
	new->refle = env->tmp.refle;
	new->refra = env->tmp.refra;
	new->color.red = env->tmp.color.red;
	new->color.green = env->tmp.color.green;
	new->color.blue = env->tmp.color.blue;
	new->tile.red = env->tmp.tile.red;
	new->tile.green = env->tmp.tile.green;
	new->tile.blue = env->tmp.tile.blue;
	new->tile.w = env->tmp.tile.w;
	new->tex = env->tmp.tex;
	new->angle = env->tmp.angle;
	new->radius = env->tmp.radius;
	new->finished = env->tmp.finished;
	new->fin[0] = env->tmp.fin[0];
	new->fin[1] = env->tmp.fin[1];
	if (env->obj)
		start = env->obj;
	if (env->tmp.id_o == 1)
	{
		if (start)
		{
			new->next = start;
			start->prev = new;
			new->prev = NULL;
			env->obj = new;
		}
		else
		{
			env->obj = new;
			env->obj->next = NULL;
			env->obj->prev = NULL;
		}
	}
	else if ((env->tmp.id_o - 1) == env->parse.objects)
	{
		while (start->next)
			start = start->next;
		new->next = NULL;
		new->prev = start;
		start->next = new;
	}
	else
	{
		i = 1;
		while (start && i < env->tmp.id_o)
		{
			if (i + 1 && i + 1 == env->tmp.id_o)
			{
				start->next->prev = new;
				new->next = start->next;
				start->next = new;
				new->prev = start;
			}
			start = start->next;
			i++;
		}
	}
}
