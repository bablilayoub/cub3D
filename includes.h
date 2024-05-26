/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:01:40 by abablil           #+#    #+#             */
/*   Updated: 2024/05/26 10:59:10 by abablil          ###   ########.fr       */
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
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 3

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
	double			ray_angle;
	double			wallHitX;
	double			wallHitY;
	int 			wasHitVertical;
	double			distance;
	int				isRayFacingDown;
	int				isRayFacingUp;
	int				isRayFacingRight;
	int				isRayFacingLeft;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*temp;
	char		*map_file;
	char 		*addr;
	void		*img;
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
	t_player	*player;
	t_ray		*rays;
}	t_data;

#endif
