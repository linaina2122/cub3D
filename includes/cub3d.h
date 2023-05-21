/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:20:43 by bkamal            #+#    #+#             */
/*   Updated: 2023/05/21 02:12:41 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h> //?
# include <math.h>
# include "../libft/includes/libft.h"

# define EXT_CUB ".cub"
# define EXT_XPM ".xpm"

//*PARSING
# define ERR_NUM_ARG "Incorrect number of arguments\n"
# define ERR_WRG_EXT "Incorrect file extension\n"
# define ERR_OPN_FIL "Cannot open given file\n"
# define ERR_ISA_DIR "Argument is a directory\n"
# define ERR_WRG_SCN "Incorrect scene configuration\n"

//*GNL
# define BUFFER_SIZE 42
//*********************

# define SCALE 64
# define WIDTH 896
# define HEIGHT 512
# define SPEED  2 * (M_PI_2 / 180)
#define WALL_STRIPE_WIDTH 1
//RAY

#define FOV_ANGLE 60 * (M_PI_2 / 180)
#define NUM_RAYS WIDTH / WALL_STRIPE_WIDTH 
#define MINI_MAP_SCALE 1

//*******************************************************
//*PARSING PART
 typedef struct s_map
 {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	char	**layout;
 }	t_map;

//*ERROR CHECKING
// void	error_checks(int ac, char **av);
// char	*get_next_line(int fd);

//*******************************************************
//TODO:EVERYTHING ELSE

//*******************************************************
//*2D MAP
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_text{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}t_text;

typedef struct s_ray {
	double xstep;
	double ystep;
	double xfirstintersecpointhor;
	double yfirstintersecpointhor;
	double xfirstintersecpointver;
	double yfirstintersecpointver;
	double rayangle;
	double next_h_interx;
	double next_h_intery;
	double next_v_interx;
	double next_v_intery;
	double wallhitx;
	double wallhity;
	float wallstrip;
	double howallx;
	double howally;
	double vwallx;
	double vwally;
	int hflag;
	int vflag;
	double final_distance;
}t_ray;

typedef struct s_my_struct{
	int		keycode;
	t_data	imge;
	t_text	t;
	char 	**map;
	void 	*mlx_ptr;
	void 	*win_ptr;
	double 	player_x;
	double 	player_y;
	double rot_player_x;
	double rot_player_y;
	double rot_angle;
	double var;
	int move[3];
	t_ray *r;
}t_my_struct;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		loop_func(t_my_struct *m);
void	player_init(t_my_struct *m);
void 	draw(t_my_struct *m);
void	draw_square(t_my_struct *m, int count, int count2);
void 	player(t_my_struct *m, double x, double y);
int 	mouvements_press(int keycode, t_my_struct *m);
int 	mouvements_release(int keycode, t_my_struct *m);
void 	draw_back(t_my_struct *m , int x, int y);
void 	window(t_my_struct *m);
void	ft_put_pixel(t_my_struct *data, int x, int y, int color);
void	data_struct_init(t_my_struct *data);
void line_draw(t_my_struct *m);
t_my_struct *my_fun(); // to remove

int 	move_up(t_my_struct *m);
int 	move_down(t_my_struct *m);
int 	right_move(t_my_struct *m);
int 	left_move(t_my_struct *m);
int 	find_wall(double x, double y, t_my_struct *m);
void 	h_intercept(t_my_struct *m, double angle);
t_ray 	*struct_init(t_my_struct *m);
void 	ray_draw(t_my_struct *m, double angle);
void 	ray_angles(t_my_struct *m);
double 	normalize_angle(double angl);
void  	v_intercept(t_my_struct *m, double angle);
void	h_intercept(t_my_struct *m, double angle);
void 	rander(t_my_struct *m);
void 	find_h_wall(t_my_struct *m);
void 	find_v_wall(t_my_struct *m);
void 	renderwalls(t_my_struct *m, double ray_angle);
void 	walls(t_my_struct *m, int count);
void	get_distance(t_my_struct *m);
int		check_left_right(double angle);
int		check_up_down(double angle);
double	distance_of_two_points(t_my_struct *m, double d1, double d2);
int	exiting(int keycode, t_my_struct *m);
int	update(t_my_struct *m);
void text_init(t_my_struct *m);

//*******************************************************

#endif