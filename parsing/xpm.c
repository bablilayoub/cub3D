/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:32:27 by abablil           #+#    #+#             */
/*   Updated: 2024/06/02 16:41:59 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_texture	*init_texture(t_data *data)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		exit_game("Malloc failed", data, -1, 1);
	texture->img = NULL;
	texture->addr = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->bits_per_pixel = 0;
	texture->line_length = 0;
	texture->endian = 0;
	return (texture);
}

// Set texture
void	set_texture(t_data *data, char *path, t_texture *texture)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_game("Texture not found", data, -1, 1);
	close(fd);
	texture->img = mlx_xpm_file_to_image(data->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
		exit_game("Texture not found", data, -1, 1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
		exit_game("Texture not found", data, -1, 1);
}

// Get torch textures
void	get_torch(t_data *data)
{
	data->torch_1_texture = init_texture(data);
	data->torch_2_texture = init_texture(data);
	data->torch_3_texture = init_texture(data);
	data->torch_4_texture = init_texture(data);
	data->torch_5_texture = init_texture(data);
	data->torch_6_texture = init_texture(data);
	data->torch_7_texture = init_texture(data);
	data->torch_8_texture = init_texture(data);
	set_texture(data, "./textures/torch/torch_1.xpm", data->torch_1_texture);
	set_texture(data, "./textures/torch/torch_2.xpm", data->torch_2_texture);
	set_texture(data, "./textures/torch/torch_3.xpm", data->torch_3_texture);
	set_texture(data, "./textures/torch/torch_4.xpm", data->torch_4_texture);
	set_texture(data, "./textures/torch/torch_5.xpm", data->torch_5_texture);
	set_texture(data, "./textures/torch/torch_6.xpm", data->torch_6_texture);
	set_texture(data, "./textures/torch/torch_7.xpm", data->torch_7_texture);
	set_texture(data, "./textures/torch/torch_8.xpm", data->torch_8_texture);
}

// Get texture from the walls
void	get_xpms(t_data *data)
{
	data->north_texture_struct = init_texture(data);
	data->south_texture_struct = init_texture(data);
	data->west_texture_struct = init_texture(data);
	data->east_texture_struct = init_texture(data);
	data->door_texture = init_texture(data);
	set_texture(data, data->north_texture, data->north_texture_struct);
	set_texture(data, data->south_texture, data->south_texture_struct);
	set_texture(data, data->west_texture, data->west_texture_struct);
	set_texture(data, data->east_texture, data->east_texture_struct);
	set_texture(data, "./textures/door.xpm", data->door_texture);
	get_torch(data);
}
