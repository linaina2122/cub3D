/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfun.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:58:18 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/19 23:53:33 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exiting(int keycode, t_my_struct *m)
{
	(void)m;
	(void)keycode;
	exit(1);
}

int	move(t_my_struct *m)
{
	if (m->move[0] == 1)
	{
		if (move_up(m))
			return (1);
	}
	if (m->move[0] == 2)
	{
		if (move_down(m))
			return (1);
	}
	if (m->move[1] == 1)
	{
		if (right_move(m))
			return (1);
	}
	if (m->move[1] == 2)
	{
		if (left_move(m))
			return (1);
	}
	return (0);
}

int	update(t_my_struct *m)
{
	m->rot_angle = normalize_angle(m->rot_angle);
	move(m);
	if (m->move[2] == 1)
		m->rot_angle += 0.8 * SPEED;
	if (m->move[2] == 2)
		m->rot_angle -= 0.8 * SPEED;
	return (0);
}

void	player_init(t_my_struct *m)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		line = m->map[i];
		while (line[j])
		{
			if (line[j] == 'N')
			{
				m->player_x = j + 0.5;
				m->player_y = i + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
}
