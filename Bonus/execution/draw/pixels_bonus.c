/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:47:02 by alaalalm          #+#    #+#             */
/*   Updated: 2024/06/04 19:00:20 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution_bonus.h"

int	get_pixel(t_texture *texture, int x, int y)
{
	int	color;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	color = *(int *)(texture->addr + (y * texture->line_length
				+ x * (texture->bits_per_pixel / 8)));
	if (color < 0)
		return (0);
	return (color);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->w_width || y < 0 || y >= data->w_height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_cl(t_data *data, int textureOffsetX, int textureOffsetY, int *color)
{
	if (data->rays->washitvertical && data->rays->israyfacingleft)
		*color = get_pixel(data->north_texture_struct, textureOffsetX
				* data->north_texture_struct->width / TILE_SIZE, textureOffsetY
				* data->north_texture_struct->height / TILE_SIZE);
	else if (data->rays->washitvertical && !data->rays->israyfacingleft)
		*color = get_pixel(data->south_texture_struct, textureOffsetX
				* data->south_texture_struct->width / TILE_SIZE, textureOffsetY
				* data->south_texture_struct->height / TILE_SIZE);
	else if (!data->rays->washitvertical && data->rays->israyfacingup)
		*color = get_pixel(data->west_texture_struct, textureOffsetX
				* data->west_texture_struct->width / TILE_SIZE, textureOffsetY
				* data->west_texture_struct->height / TILE_SIZE);
	else if (!data->rays->washitvertical && !data->rays->israyfacingup)
		*color = get_pixel(data->east_texture_struct, textureOffsetX
				* data->east_texture_struct->width / TILE_SIZE, textureOffsetY
				* data->east_texture_struct->height / TILE_SIZE);
}

int	get_texture_color(t_data *data, int textureOffsetX, int textureOffsetY)
{
	int		color;

	color = 0;
	if (data->map[(int)data->rays->wallhity / TILE_SIZE]
		[(int)data->rays->wallhitx / TILE_SIZE] == 'D')
		color = get_pixel(data->door_texture, textureOffsetX
				* data->door_texture->width / TILE_SIZE, textureOffsetY
				* data->door_texture->height / TILE_SIZE);
	else
		get_cl(data, textureOffsetX, textureOffsetY, &color);
	return (color);
}

int	rgb_to_int(int *rgb)
{
	int		color;

	color = 0;
	color = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (color);
}
