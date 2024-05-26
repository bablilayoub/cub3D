/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:42:25 by alaalalm          #+#    #+#             */
/*   Updated: 2024/05/26 12:32:55 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../cub3D.h"

// set up
void		set_up_window(t_data *data, int w_height, int  w_width);

// rendering
int			draw(void *param);

// movement
int 		key_press(int keycode, t_data *data);
int 		key_release(int keycode, t_data *data);
int			update_player_pos(t_data *data, double newPlayerX, double newPlayerY);
void		initialize_player(t_data *data);
void		execute(t_data *data);
void line(t_data *data, int x0, int y0, int x1, int y1);
void update(t_data *data);
void    castAllRays(t_data *data);
#endif