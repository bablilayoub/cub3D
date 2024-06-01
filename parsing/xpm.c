/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:32:27 by abablil           #+#    #+#             */
/*   Updated: 2024/06/01 12:09:08 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Get torch textures
void	get_torch(t_data *data)
{
	data->torch_1_texture = malloc(sizeof(t_texture));
	data->torch_2_texture = malloc(sizeof(t_texture));
	data->torch_3_texture = malloc(sizeof(t_texture));
	data->torch_4_texture = malloc(sizeof(t_texture));
	data->torch_5_texture = malloc(sizeof(t_texture));
	data->torch_6_texture = malloc(sizeof(t_texture));
	data->torch_7_texture = malloc(sizeof(t_texture));
	data->torch_8_texture = malloc(sizeof(t_texture));
	if (!data->torch_1_texture || !data->torch_2_texture || !data->torch_3_texture || !data->torch_4_texture || !data->torch_5_texture || !data->torch_6_texture || !data->torch_7_texture || !data->torch_8_texture)
		exit_game("Malloc failed", data, -1, 1);
	data->torch_1_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_1.xpm", &data->torch_1_texture->width, &data->torch_1_texture->height);
	data->torch_2_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_2.xpm", &data->torch_2_texture->width, &data->torch_2_texture->height);
	data->torch_3_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_3.xpm", &data->torch_3_texture->width, &data->torch_3_texture->height);
	data->torch_4_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_4.xpm", &data->torch_4_texture->width, &data->torch_4_texture->height);
	data->torch_5_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_5.xpm", &data->torch_5_texture->width, &data->torch_5_texture->height);
	data->torch_6_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_6.xpm", &data->torch_6_texture->width, &data->torch_6_texture->height);
	data->torch_7_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_7.xpm", &data->torch_7_texture->width, &data->torch_7_texture->height);
	data->torch_8_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/torch/torch_8.xpm", &data->torch_8_texture->width, &data->torch_8_texture->height);
	if (!data->torch_1_texture->img || !data->torch_2_texture->img || !data->torch_3_texture->img || !data->torch_4_texture->img || !data->torch_5_texture->img || !data->torch_6_texture->img || !data->torch_7_texture->img || !data->torch_8_texture->img)
		exit_game("Torch texture not found", data, -1, 1);
	data->torch_1_texture->addr = mlx_get_data_addr(data->torch_1_texture->img, &data->torch_1_texture->bits_per_pixel, &data->torch_1_texture->line_length, &data->torch_1_texture->endian);
	data->torch_2_texture->addr = mlx_get_data_addr(data->torch_2_texture->img, &data->torch_2_texture->bits_per_pixel, &data->torch_2_texture->line_length, &data->torch_2_texture->endian);
	data->torch_3_texture->addr = mlx_get_data_addr(data->torch_3_texture->img, &data->torch_3_texture->bits_per_pixel, &data->torch_3_texture->line_length, &data->torch_3_texture->endian);
	data->torch_4_texture->addr = mlx_get_data_addr(data->torch_4_texture->img, &data->torch_4_texture->bits_per_pixel, &data->torch_4_texture->line_length, &data->torch_4_texture->endian);
	data->torch_5_texture->addr = mlx_get_data_addr(data->torch_5_texture->img, &data->torch_5_texture->bits_per_pixel, &data->torch_5_texture->line_length, &data->torch_5_texture->endian);
	data->torch_6_texture->addr = mlx_get_data_addr(data->torch_6_texture->img, &data->torch_6_texture->bits_per_pixel, &data->torch_6_texture->line_length, &data->torch_6_texture->endian);
	data->torch_7_texture->addr = mlx_get_data_addr(data->torch_7_texture->img, &data->torch_7_texture->bits_per_pixel, &data->torch_7_texture->line_length, &data->torch_7_texture->endian);
	data->torch_8_texture->addr = mlx_get_data_addr(data->torch_8_texture->img, &data->torch_8_texture->bits_per_pixel, &data->torch_8_texture->line_length, &data->torch_8_texture->endian);
}

// Get texture from the walls
void	get_xpms(t_data *data)
{
	// data->texture[0].img = mlx_xpm_file_to_image(data->mlx, data->north_texture, &data->texture[0].width, &data->texture[0].height);
	// data->texture[1].img = mlx_xpm_file_to_image(data->mlx, data->south_texture, &data->texture[1].width, &data->texture[1].height);
	// data->texture[2].img = mlx_xpm_file_to_image(data->mlx, data->west_texture, &data->texture[2].width, &data->texture[2].height);
	// data->texture[3].img = mlx_xpm_file_to_image(data->mlx, data->east_texture, &data->texture[3].width, &data->texture[3].height);
	// if (!data->texture[0].img || !data->texture[1].img || !data->texture[2].img || !data->texture[3].img || !data->texture[4].img)
	// 	exit_game("Texture not found", data, -1, 1);
	// data->texture[0].addr = mlx_get_data_addr(data->texture[0].img, &data->texture[0].bits_per_pixel, &data->texture[0].line_length, &data->texture[0].endian);
	// data->texture[1].addr = mlx_get_data_addr(data->texture[1].img, &data->texture[1].bits_per_pixel, &data->texture[1].line_length, &data->texture[1].endian);
	// data->texture[2].addr = mlx_get_data_addr(data->texture[2].img, &data->texture[2].bits_per_pixel, &data->texture[2].line_length, &data->texture[2].endian);
	// data->texture[3].addr = mlx_get_data_addr(data->texture[3].img, &data->texture[3].bits_per_pixel, &data->texture[3].line_length, &data->texture[3].endian);
	get_torch(data);
}
