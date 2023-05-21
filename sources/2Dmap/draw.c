/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:15:00 by hcharef           #+#    #+#             */
/*   Updated: 2023/05/21 00:48:11 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_struct_init(t_my_struct *data)
{
	data->imge.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->imge.addr = mlx_get_data_addr(data->imge.img, \
	&data->imge.bpp, &data->imge.line_length, &data->imge.endian);
}

void	ft_put_pixel(t_my_struct *data, int x, int y, int color)
{
	int		offset;
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * data->imge.line_length) + (x * (data->imge.bpp / 8));
	dst = data->imge.addr + offset;
	*(unsigned int *)dst = color;
}

// void	draw_square(t_my_struct *m, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < (SCALE * MINI_MAP_SCALE))
// 	{
// 		j = 0;
// 		while (j < (SCALE * MINI_MAP_SCALE))
// 		{
// 			ft_put_pixel(m, x + j, y, 0x000000);
// 			ft_put_pixel(m, x + j, y + i, 0x000000);
// 			j++;
// 		}
// 		ft_put_pixel(m, x, y + i, 0x000000);
// 		i++;
// 	}
// }

// void	draw_back(t_my_struct *m, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < (SCALE * MINI_MAP_SCALE))
// 	{
// 		j = 0;
// 		while (j < (SCALE * MINI_MAP_SCALE))
// 		{
// 			ft_put_pixel(m, x + j, y, 0x000000);
// 			ft_put_pixel(m, x + j, y + i, 0x000000);
// 			j++;
// 		}
// 		ft_put_pixel(m, x, y + i, 0x000000);
// 		i++;
// 	}
// }

void	draw(t_my_struct *m)
{
	int	x;
	int	y;

	x = 0;
	while (x < HEIGHT / 2)
	{
		y = 0;
		while (y < WIDTH)
		{
			ft_put_pixel(m, y, x, 0x008bec);
			y++;
		}
		x++;
	}
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			ft_put_pixel(m, y, x, 0x353422);
			y++;
		}
		x++;
	}
}
