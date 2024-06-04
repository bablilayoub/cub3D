/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendertorch_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:49:08 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/04 19:01:02 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

void	render_it(t_data *data, int x, int y)
{
	int	color;

	color = 0;
	if (data->flag < 5)
		color = get_pixel(data->torch_1_texture, x, y);
	else if (data->flag >= 5 && data->flag < 10)
		color = get_pixel(data->torch_2_texture, x, y);
	else if (data->flag >= 10 && data->flag < 15)
		color = get_pixel(data->torch_3_texture, x, y);
	else if (data->flag >= 15 && data->flag < 20)
		color = get_pixel(data->torch_4_texture, x, y);
	else if (data->flag >= 20 && data->flag < 25)
		color = get_pixel(data->torch_5_texture, x, y);
	else if (data->flag >= 25 && data->flag < 30)
		color = get_pixel(data->torch_6_texture, x, y);
	else if (data->flag >= 30 && data->flag < 35)
		color = get_pixel(data->torch_7_texture, x, y);
	else if (data->flag >= 35 && data->flag < 40)
		color = get_pixel(data->torch_8_texture, x, y);
	if (color != 0)
		my_mlx_pixel_put(data, data->torch.middle_x + x,
			data->torch.bottom_y + y, color);
}

void	render_torch(t_data *data)
{
	int		x;
	int		y;

	data->torch.torch_width = data->torch_1_texture->width;
	data->torch.torch_height = data->torch_1_texture->height;
	data->torch.middle_x = data->w_width / 1.4 - data->torch.torch_width / 2;
	data->torch.bottom_y = data->w_height - data->torch.torch_height;
	x = -1;
	if (data->flag >= 40)
		data->flag = 1;
	while (++x < data->torch.torch_width)
	{
		y = -1;
		while (++y < data->torch.torch_height)
			render_it(data, x, y);
	}
	data->flag++;
}
