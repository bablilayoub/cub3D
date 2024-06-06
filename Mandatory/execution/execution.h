/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:42:25 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/06 13:41:09 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../../cub3D.h"
// set up
void	set_up_window(t_data *data);
// movement
void	initialize_player(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	update_player_pos(t_data *data, double newPlayerX, double newPlayerY);
void	initialize_player(t_data *data);
// Cast rays
void	castallrays(t_data *data);
void	castray(t_data *data, double rayAngle);
void	findhorizwallhit(t_data *data, t_ray *ray);
void	findverticalwallhit(t_data *data, t_ray *ray);
// utils
int		has_wall_at(t_data *data, double x, double y);
double	normalize_angle(double angle);
double	vector_lenght(double x1, double y1, double x2, double y2);

// rendering
int		draw(void *param);
void	render_column(t_data *data, int rayId,
			double distance, double rayAngle);
// main
void	execute(t_data *data);

// door
t_doors	*get_last(t_doors *doors);
t_doors	*add_new(int y, int x);
void	add_back(t_doors **doors, t_doors *newDoor);
void	find_doors(t_data *data);
int		check_closest_door(t_data *data, int index_x, int index_y);
int		check_if_compatibles(t_data *data, int index_x, int index_y);
void	upadte_values(t_data *data);
void	create_image(t_data *data);

// utils
int		get_pixel(t_texture *texture, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// texture
int		rgb_to_int(int *rgb);
int		get_texture_color(t_data *data, int textureOffsetX, int textureOffsetY);

#endif