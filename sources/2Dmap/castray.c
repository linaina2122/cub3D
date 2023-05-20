/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:35:51 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/19 23:39:43 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_h_wall(t_my_struct *m)
{
	while (m->r->next_h_interx >= 0 && m->r->next_h_interx <= WIDTH && \
	m->r->next_h_intery >= 0 && m->r->next_h_intery <= HEIGHT)
	{
		if (find_wall(m->r->next_h_interx / SCALE, \
		m->r->next_h_intery / SCALE, m))
		{
			m->r->hflag = 1;
			m->r->howallx = m->r->next_h_interx;
			m->r->howally = m->r->next_h_intery;
			break ;
		}
		else
		{
			m->r->next_h_interx += m->r->xstep;
			m->r->next_h_intery += m->r->ystep;
		}
	}
}

void	h_intercept(t_my_struct *m, double angle)
{
	m->r->hflag = 0;
	m->r->howallx = 0;
	m->r->howally = 0;
	m->r->yfirstintersecpointhor = floor((m->player_y * SCALE) / SCALE) * SCALE;
	if (check_up_down(angle))
		m->r->yfirstintersecpointhor += SCALE;
	m->r->xfirstintersecpointhor = (m->player_x * SCALE) + \
		(m->r->yfirstintersecpointhor - (m->player_y * SCALE)) / tan(angle);
	m->r->ystep = SCALE;
	if (!(check_up_down(angle)))
		m->r->ystep *= -1;
	m->r->xstep = SCALE / tan(angle);
	if (!(check_left_right(angle)) && m->r->xstep > 0)
		m->r->xstep *= -1;
	if (check_left_right(angle) && m->r->xstep < 0)
		m->r->xstep *= -1;
	m->r->next_h_interx = m->r->xfirstintersecpointhor;
	m->r->next_h_intery = m->r->yfirstintersecpointhor;
	if (!(check_up_down(angle)))
		m->r->next_h_intery--;
	find_h_wall(m);
}

void	find_v_wall(t_my_struct *m)
{
	while (m->r->next_v_interx >= 0 && m->r->next_v_interx <= WIDTH && \
	m->r->next_v_intery >= 0 && m->r->next_v_intery <= HEIGHT)
	{
		if (find_wall(m->r->next_v_interx / SCALE, m->r->next_v_intery / SCALE,
				m))
		{
			m->r->vflag = 1;
			m->r->vwallx = m->r->next_v_interx;
			m->r->vwally = m->r->next_v_intery;
			break ;
		}
		else
		{
			m->r->next_v_interx += m->r->xstep;
			m->r->next_v_intery += m->r->ystep;
		}
	}
}

void	v_intercept(t_my_struct *m, double angle)
{
	m->r->vflag = 0;
	m->r->vwallx = 0;
	m->r->vwally = 0;
	m->r->xfirstintersecpointver = floor((m->player_x * SCALE) / SCALE) * SCALE;
	if (check_left_right(angle))
		m->r->xfirstintersecpointver += SCALE;
	m->r->yfirstintersecpointver = (m->player_y * SCALE) + \
		(m->r->xfirstintersecpointver - (m->player_x * SCALE)) * tan(angle);
	m->r->xstep = SCALE;
	if (!(check_left_right(angle)))
		m->r->xstep *= -1;
	m->r->ystep = SCALE * tan(angle);
	if (!(check_up_down(angle)) && m->r->ystep > 0)
		m->r->ystep *= -1;
	if (check_up_down(angle) && m->r->ystep < 0)
		m->r->ystep *= -1;
	m->r->next_v_interx = m->r->xfirstintersecpointver;
	m->r->next_v_intery = m->r->yfirstintersecpointver;
	if (!(check_left_right(angle)))
		m->r->next_v_interx--;
	find_v_wall(m);
}

void	get_distance(t_my_struct *m)
{
	double	vertic;
	double	hory;

	if (m->r->vflag == 1)
		vertic = distance_of_two_points(m, m->r->vwallx, m->r->vwally);
	else
		vertic = HEIGHT * 2;
	if (m->r->hflag == 1)
		hory = distance_of_two_points(m, m->r->howallx, m->r->howally);
	else
		hory = WIDTH * 2;
	if (vertic > hory)
		m->r->final_distance = hory;
	else
		m->r->final_distance = vertic;
}
