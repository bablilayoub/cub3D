/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:42:25 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/01 16:52:08 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../cub3D.h"

// set up
void		set_up_window(t_data *data, int w_height, int  w_width);

// movement
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		update_player_pos(t_data *data, double newPlayerX, double newPlayerY);
void	initialize_player(t_data *data);


// Cast rays
void	castAllRays(t_data *data);
void	castRay(t_data *data, double rayAngle);
void	findHorizWallHit(t_data *data, t_ray *ray);
void	findVerticalWallHit(t_data *data, t_ray *ray);
void	line(t_data *data, int x0, int y0, int x1, int y1);
// void	add_line_toplayer(t_data *data, double rayAngle);


// utils
int		has_wall_at(t_data *data, double x, double y);
double	normalize_angle(double angle);
double	vector_lenght(double x1, double y1, double x2, double y2);

// rendering
int     draw(void *param);
int		draw(void *param);
void	render_map(t_data *data);
void	render_player(t_data *data, int color);
// void  	render_column(t_data *data, int rayId, double rayAngle, double distance);

// main
void	execute(t_data *data);

#endif