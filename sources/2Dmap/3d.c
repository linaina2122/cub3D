/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:50:07 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/19 21:08:22 by hcharef          ###   ########.fr       */
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

void	walls(t_my_struct *m, double count)
{
	double	count2;

	count2 = (HEIGHT / 2) - (m->r->wallstrip / 2);
	while (count2 < (HEIGHT / 2) + (m->r->wallstrip / 2))
	{
		ft_put_pixel(m, count, count2, 0xdc9bc1);
		count2++;
	}
}

void	renderwalls(t_my_struct *m, double ray_angle)
{
	double	disprojectionplane;
	double	correctwalldist;

	correctwalldist = (float)(m->r->final_distance) * cos(ray_angle
			- m->rot_angle);
	disprojectionplane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	m->r->wallstrip = (SCALE / correctwalldist) * disprojectionplane;
}
