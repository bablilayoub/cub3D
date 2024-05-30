/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:01:40 by abablil           #+#    #+#             */
/*   Updated: 2024/05/30 14:47:05 by alaalalm         ###   ########.fr       */
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
# define TILE_SIZE 32
# define FOV 60
# define FOV_ANGLE (FOV * (M_PI / 180))
# define ROTATION_SPEED 6
# define MOVE_SPEED 2.0
# define RADIUS 3

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
	double	rotation_angle;
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

	int foundHorzWallHit;
	double horzWallHitX;
	double horzWallHitY;
	int horzWallContent;
	double nextHorzTouchX;
	double nextHorzTouchY;


	int foundVertWallHit;
	double vertWallHitX;
	double vertWallHitY;
	int vertWallContent;
	double nextVertTouchX;
	double nextVertTouchY;

	double xToCheck;
	double yToCheck;



	double horzHitDistance;
	double vertHitDistance;
	double distance;
	double wallHitX;
	double wallHitY;


	double wasHitVertical;
	double wallHitContent;
}	t_ray;

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
	double		newPlayerX;
	double		newPlayerY;
	double 		rayAngle;
	t_player	*player;
	t_ray		*rays;
}	t_data;

#endif
