/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:01:40 by abablil           #+#    #+#             */
/*   Updated: 2024/06/01 10:34:54 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
#define INCLUDES_H

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
# define TILE_SIZE 50
# define FOV 60
# define FOV_ANGLE (FOV * (M_PI / 180))
# define ROTATION_SPEED 6
# define MOVE_SPEED 4.0
# define RADIUS 2
# define MINIMAP_SCALE_FACTOR 0.15

# define ESCP	53
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_W	13


# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126

typedef struct s_player
{
	int		turn_direction;
	int		walk_direction;
	int		movement;
	double	posX;
	double	posY;
	double	facing_angle;
	double	move_speed;
	double	rotation_speed;
	double	radius;
}	t_player;

typedef struct s_ray
{
	int		isRayFacingDown;
	int		isRayFacingUp;
	int		isRayFacingRight;
	int		isRayFacingLeft;
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;

	// horizontal
	int horzWallContent;
	double horzWallHitX;
	double horzWallHitY;
	double nextHorzTouchX;
	double nextHorzTouchY;
	double wasHitHorizontal;
	double horzHitDistance;

	// vertical
	int vertWallContent;
	double vertWallHitX;
	double vertWallHitY;
	double nextVertTouchX;
	double nextVertTouchY;
	double wasHitVertical;
	double vertHitDistance;

	
	double distance;
	double wallHitX;
	double wallHitY;
	double wallHitContent;
	double rayAngle;
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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*temp;
	char		*map_file;
	char 		*addr;
	void		*img;
	int 		flag;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	int			start_point;
	int			map_height;
	int			map_width;
	int			player_x;
	int			player_y;
	size_t		biggest_line;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*floor_color;
	char		*ceiling_color;
	t_texture	*torch_1_texture;
	t_texture	*torch_2_texture;
	t_texture	*torch_3_texture;
	t_texture	*torch_4_texture;
	t_texture	*torch_5_texture;
	t_texture	*torch_6_texture;
	t_texture	*torch_7_texture;
	t_texture	*torch_8_texture;
	int			torch_width;
	int			torch_height;
	double		newPlayerX;
	double		newPlayerY;
	double 		rayAngle;
	int			W_Width;
	int			W_Height;
	t_player	*player;
	t_ray		*rays;
	t_texture	texture[5];
}	t_data;

#endif
