/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:05:37 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/19 23:36:28 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angl)
{
	double	angle;

	angle = fmod(angl, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

int	check_up_down(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	return (0);
}

int	check_left_right(double angle)
{
	if (angle < M_PI_2 || angle > 1.5 * M_PI)
		return (1);
	return (0);
}

int	find_wall(double x, double y, t_my_struct *m)
{
	if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT)
		return (1);
	if (m->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

double	distance_of_two_points(t_my_struct *m, double d1, double d2)
{
	double	c;

	c = (pow((d1 - m->player_x * SCALE), 2) + pow((d2 - m->player_y * SCALE),
				2));
	return (sqrt(c));
}
