/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:42:25 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/25 18:34:45 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../cube3D.h"
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
# include "../cube3D.h"

#define MAP_W 24
#define MAP_H 24
# define TILE_SIZE 32
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 3
# define PI 3.1415926535

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
	double	posX;
	double	posY;
	int		turn_direction;
	int		walk_direction;
	int		movement;
	int		walk2_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	double	radius;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		was_hit_vertical;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	int		wall_hit_content;
}	t_ray;

typedef struct s_garbage
{
	void	*ptr;
	void	**ptr_2D;
	struct s_garbage	*next;
}	t_garbage;

typedef struct s_exec
{
	void		*mlx;
	void		*mlx_win;
	char		**Map;
	void		*img;
	char			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*temp;
	int			map_width;
	int			map_height;
	char		*map_path;
	t_player	player;
	t_ray		ray;
	t_garbage   *garbage;
}	t_exec;


// linked lists
t_garbage	*exec_lstnew();
void		exec_lstadd_back(t_garbage **lst, t_garbage *new);
void		exec_lstiter(t_garbage	*lst);

void		*allocate(t_exec *data, void ***db_ptr, void **ptr, int size);

// set up
void		Set_up_Window(t_exec *data, int W_Height, int  W_Width);

// rendering
int			draw(void *param);

void		exit_game(t_exec *data);

// player
int 		key_press(int keycode, t_exec *data);
int 		key_release(int keycode, t_exec *data);
void		initialize_player(t_exec *data);
#endif