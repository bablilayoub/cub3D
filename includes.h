/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:01:40 by abablil           #+#    #+#             */
/*   Updated: 2024/06/04 22:06:36 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_BONUS_H
# define INCLUDES_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <sys/types.h>

# define GAME_NAME "Cub3D"
# define TILE_SIZE 40
# define FOV 60
# define FOV_ANGLE 1.0471975511965976
# define ROTATION_SPEED 6
# define MOVE_SPEED 4.0
# define RADIUS 2
# define MINIMAP_SCALE_FACTOR 0.15

# define ESCP	53
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_W	13
# define DOOR_OPENED 49

# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126

typedef struct s_player
{
	int		turn_direction;
	int		walk_direction;
	int		movement;
	double	pos_x;
	double	pos_y;
	double	angle;
	double	speed;
	double	rotation_speed;
	double	radius;
}	t_player;

typedef struct s_doors
{
	int				isopen;
	int				doorx;
	int				doory;
	char			current_cell;
	struct s_doors	*next;
}	t_doors;

typedef struct s_ray
{
	int		israyfacingdown;
	int		israyfacingup;
	int		israyfacingright;
	int		israyfacingleft;
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;

	// horizontal
	double	horzwallhitx;
	double	horzwallhity;
	double	nexthorztouchx;
	double	nexthorztouchy;
	double	washithorizontal;
	double	horzhitdistance;
	
	// vertical
	double	vertwallhitx;
	double	vertwallhity;
	double	nextverttouchx;
	double	nextverttouchy;
	double	washitvertical;
	double	verthitdistance;

	double	distance;
	double	wallhitx;
	double	wallhity;
	double	wallhitcontent;
}	t_ray;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_torch
{
	int		torch_width;
	int		torch_height;
	int		middle_x;
	int		bottom_y;
}	t_torch;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*temp;
	char		*map_file;
	char		*addr;
	void		*img;
	int			flag;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	int			start_point;
	int			map_height;
	int			map_width;
	int			player_x;
	int			player_y;
	int			jumpscare;
	int			jumpscare_timer;
	int			wallstrip_height;
	int			walltop_pixel;
	int			wallbottom_pixel;
	int			texture_offsetx;
	int			texture_offsety;
	int			texture_color;
	int			distance_proj_plane;
	double		correct_distance;
	size_t		biggest_line;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*floor_color;
	int			*floor_color_rgb;
	char		*ceiling_color;
	int			*ceiling_color_rgb;
	int			torch_width;
	int			torch_height;
	double		newplayerx;
	double		newplayery;
	int			w_width;
	int			w_height;
	t_player	*player;
	t_ray		*rays;
	t_doors		*doors;
	t_torch		torch;
	t_texture	*north_texture_struct;
	t_texture	*south_texture_struct;
	t_texture	*west_texture_struct;
	t_texture	*east_texture_struct;
	t_texture	*door_texture;
	t_texture	*ghost_texture;
	t_texture	*torch_1_texture;
	t_texture	*torch_2_texture;
	t_texture	*torch_3_texture;
	t_texture	*torch_4_texture;
	t_texture	*torch_5_texture;
	t_texture	*torch_6_texture;
	t_texture	*torch_7_texture;
	t_texture	*torch_8_texture;
}	t_data;

#endif
