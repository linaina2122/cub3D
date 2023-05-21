/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:41:24 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/21 09:37:42 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *worldMap[8] = {
	"11111111111111",
	"10000000000001",
	"10000000000001",
	"10000N00000001",
	"10000000000001",
	"10000000000001",
	"10000000000001",
	"11111111111111",
	};

t_my_struct *my_fun()
{
	t_my_struct *m;

	m = malloc(sizeof(t_my_struct));
	m->map = malloc(sizeof(char *) * 9);

	int count;
	count = 0;
	while(count < 8)
	{
		m->map[count] = ft_strdup(worldMap[count]);
		count++;
	}
	m->map[count] = NULL;
	return(m);
}

void player(t_my_struct *m, double x, double y)
{
	int i;
	int j;
	double count;
	double count2;
	count = x * (SCALE * MINI_MAP_SCALE);
	count2 = y * (SCALE * MINI_MAP_SCALE); 
	i = (-5 * MINI_MAP_SCALE); 
	while(i < (5 * MINI_MAP_SCALE))
	{ 
		j = (-5 * MINI_MAP_SCALE);
		while(j < (5 * MINI_MAP_SCALE))
		{
			ft_put_pixel(m, count + j, count2 + i, 0x00FF0000);
			j++;
		}
		i++;
	}
}
/*
int mouvements(int keycode, t_my_struct *m)
{
	m->rot_angle = normalize_angle(m->rot_angle);
	if(keycode == 13)
	{
		if(move_up(m))
			return(1);
	}
	if(keycode == 1)
	{
		if(move_down(m))
			return(1);
	}
	if(keycode == 0)
	{
		if(right_move(m))
			return(1);
	}
	if(keycode == 2)
	{
		if(left_move(m))
			return(1);
	}
	if (keycode == 53)
		exit(1);
	if(keycode == 124)
		m->rot_angle += 8 * SPEED;
	if(keycode == 123)
		m->rot_angle -= 8 * SPEED;
	return(keycode);
}*/

int mouvements_press(int keycode, t_my_struct *m)
{
	if (keycode == 13)
		m->move[0] = 1;
	if (keycode == 1)
		m->move[0] = 2;

	if(keycode == 0)
		m->move[1] = 1;
	if (keycode == 2)
		m->move[1] = 2;

	if(keycode == 124)
		m->move[2] = 1;
	if( keycode == 123)
		m->move[2] = 2;
		
	if (keycode == 53)
		exit(1);
	return(keycode);
}

int mouvements_release(int keycode, t_my_struct *m)
{
	if(keycode == 13 || keycode == 1)
		m->move[0] = 0;
	if(keycode == 0 || keycode == 2)
		m->move[1] = 0;
	if(keycode == 124 || keycode == 123)
		m->move[2] = 0;
	if (keycode == 53)
		exit(1);
	return(keycode);
}
