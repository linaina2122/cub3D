/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:51:00 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/21 02:19:01 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window(t_my_struct *m)
{
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIDTH, HEIGHT, "hello");
	data_struct_init(m);
	text_init(m);
	mlx_hook(m->win_ptr, ON_KEYDOWN, 0, mouvements_press, m);
	mlx_hook(m->win_ptr, ON_KEYUP, 0, mouvements_release, m);
	mlx_hook(m->win_ptr, ON_DESTROY, 0, exiting, m);
	mlx_loop_hook(m->mlx_ptr, loop_func, m);
	mlx_loop(m->mlx_ptr);
}

int	loop_func(t_my_struct *m)
{
	draw(m);
	m->r->rayangle = normalize_angle(m->rot_angle);
	rander(m);
	update(m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->imge.img, 0, 0);
	return (0);
}
