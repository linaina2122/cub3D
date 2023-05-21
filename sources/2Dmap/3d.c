/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:50:07 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/21 14:57:24 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rander(t_my_struct *m)
{
	int		count;
	double	ray_angle;

	count = 0;
	ray_angle = m->r->rayangle - (FOV_ANGLE / 2);
	ray_angle = normalize_angle(ray_angle);
	while (count < NUM_RAYS)
	{
		h_intercept(m, ray_angle);
		v_intercept(m, ray_angle);
		get_distance(m);
		renderwalls(m, ray_angle);
		walls(m, count);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		ray_angle = normalize_angle(ray_angle);
		count++;
	}
}
void text_init(t_my_struct *m)
{
	char *path;
	int i;
	(void)i;
	path = "textures/test.xpm";
	m->t.img = mlx_xpm_file_to_image(m->mlx_ptr, path, &i, &i);
	m->t.addr = mlx_get_data_addr(m->t.img, &m->t.bpp, &m->t.line_length, &m->t.endian);
}

int	ft_get_pixel(t_text m, int x, int y)
{
	int		offset;
	char	*dst;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return -1;
	offset = (y * m.line_length) + (x * (m.bpp / 8));
	dst = m.addr + offset;
	return(*(int *)dst);
}

void	walls(t_my_struct *m, int count)
{
	int	top_of_wall;
	int end_of_wall;
	int x;
	int y = 0;
	int	save;

	top_of_wall = (HEIGHT / 2) - (m->r->wallstrip / 2);
	end_of_wall = (HEIGHT / 2) + (m->r->wallstrip / 2);
	int height_wall = end_of_wall - top_of_wall;
	save = top_of_wall;
	if(top_of_wall < 0)
		top_of_wall = 0;
	if(height_wall > HEIGHT)
		height_wall = HEIGHT;
	if(m->r->hflag)
		x = ((int)m->r->howallx % SCALE);
	else if(m->r->vflag)
		x = ((int)m->r->vwally % SCALE);
	while (top_of_wall < end_of_wall)
	{
		y = (top_of_wall - save) / height_wall;
		printf("y is  = %d\n", y);
		int color = ft_get_pixel(m->t, x + count, y);
		ft_put_pixel(m, count, top_of_wall, color);
		top_of_wall++;
	}
}

void	renderwalls(t_my_struct *m, double ray_angle)
{
	double	disprojectionplane;
	double	correctwalldist;

	correctwalldist = (float)(m->r->final_distance) * cos(ray_angle\
			- m->rot_angle);
	disprojectionplane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	m->r->wallstrip = (SCALE / correctwalldist) * disprojectionplane;
}
