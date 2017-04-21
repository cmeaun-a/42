/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:22:48 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/04/21 04:59:27 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_cam(t_cam *cam, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp("camera", &str[i], 6) == 0)
		{
			while (isdigit(str[i]) == 0)
				i++;
			cam->origin.x = ft_atoi(&str[i]);
			while (str[i] != ' ')
				i++;
			cam->origin.y = ft_atoi(&str[i]);
			while (str[i] != ' ')
				i++;
			cam->origin.z = ft_atoi(&str[i]);
		}
		i++;
	}
}

void		get_origin_sphere(t_sphere *o, char *str)
{
	int i;

	i = 0;
	while (isdigit(str[i]) == 0)
		i++;
	o->pos.x = ft_atoi(&str[i]);
	while (str[i] != ' ')
		i++;
	i++;
	o->pos.y = ft_atoi(&str[i]);
	while (str[i] != ' ')
		i++;
	i++;
	o->pos.z = ft_atoi(&str[i]);
}

void		get_radius_sphere(t_sphere *r, char *str)
{
	int i;

	i = 0;
	while (isdigit(str[i]) == 0)
		i++;
	r->radius = ft_atoi(&str[i]);
}

void		get_color_sphere(t_sphere *c, char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	while (isdigit(str[i]) == 0)
		i++;
	r = ft_atoi(&str[i]);
	while (str[i] != ' ')
		i++;
	g = ft_atoi(&str[i]);
	while (str[i] != ' ')
		i++;
	b = ft_atoi(&str[i]);
	c->color = rgb(r, g, b);
}

t_li		*get_objets(char *str)
{
	int i;
	t_sphere sphere;
	t_li *obj = NULL;

	i = 0;

	while (str[i])
	{
		if (ft_strncmp("object", &str[i], 6) == 0)
		{
			while (str[i])
			{
				if (ft_strncmp("sphere", &str[i], 6) == 0)
				{
					if (!((obj) = (t_li *)malloc(sizeof(t_li))))
						return (0);
					obj->name = SPHERE;
					while (ft_strncmp("origin", &str[i], 6))
						i++;
					get_origin_sphere(&sphere, &str[i]);
					obj->data = &sphere;
					while (ft_strncmp("radius", &str[i], 6))
						i++;
					get_radius_sphere((t_sphere *)(obj->data), &str[i]);
					while (ft_strncmp("color", &str[i], 5))
						i++;
					get_color_sphere((t_sphere *)(obj->data), &str[i]);
					obj->next = NULL;
				}
				else if (ft_strncmp("cone", &str[i], 4) == 0)
				{
					obj->name = CONE;
					while (isdigit(str[i]) == 0)
						i++;
				}
				else if (ft_strncmp("cylindre", &str[i], 8) == 0)
				{
					obj->name = CYL;
					while (isdigit(str[i]) == 0)
						i++;
				}
				else if (ft_strncmp("plane", &str[i], 5) == 0)
				{
					obj->name = PLANE;
					while (isdigit(str[i]) == 0)
						i++;
				}
				i++;
			}
		}
		i++;
	}
	printf("x = %.0f\n", ((t_sphere *)(obj->data))->pos.x);
	printf("y = %.0f\n", ((t_sphere *)(obj->data))->pos.y);
	printf("z = %.0f\n", ((t_sphere *)(obj->data))->pos.z);
	printf("radius = %.0f\n", ((t_sphere *)(obj->data))->radius);
	printf("color = %x\n", ((t_sphere *)(obj->data))->color);
	return (obj);
}

void		ft_get_info(t_scene *scene, char *str)
{
	get_cam(&(scene)->cam, str);
	if (!(scene->obj = (t_li *)malloc(sizeof(t_li))))
		return ;
	(scene)->obj = get_objets(str);
	printf("	x = %.0f\n", ((t_sphere *)(scene->obj->data))->pos.x);
	printf("	y = %.0f\n", ((t_sphere *)(scene->obj->data))->pos.y);
	printf("	z = %.0f\n", ((t_sphere *)(scene->obj->data))->pos.z);
	printf("	radius = %.0f\n", ((t_sphere *)(scene->obj->data))->radius);
	printf("	color = %x\n", ((t_sphere *)(scene->obj->data))->color);
}

void		ft_get_scene(t_scene *scene, char *av)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE];
	char	*str;

	str = ft_strnew(0);
	if ((fd = open(av, O_RDONLY)) < 0)
		return ;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return ;
		buff[ret] = '\0';
		str = ft_strjoinf(str, buff);
	}
	ft_get_info(scene, str);
	printf("name = %d\n", (scene)->obj->name);
	printf("cam x = %.0f\n", (scene)->cam.origin.x);
	printf("cam y = %.0f\n", (scene)->cam.origin.y);
	printf("cam z = %.0f\n", (scene)->cam.origin.z);
	printf("obj x = %.0f\n", ((t_sphere*)((scene)->obj->data))->pos.x);
	printf("obj y = %.0f\n", ((t_sphere*)((scene)->obj->data))->pos.y);
	printf("obj z = %.0f\n", ((t_sphere*)((scene)->obj->data))->pos.z);
	printf("radius = %.0f\n", ((t_sphere*)((scene)->obj->data))->radius);
	printf("color = %.x\n", ((t_sphere*)((scene)->obj->data))->color);
	printf("\n");
	close(fd);
}
