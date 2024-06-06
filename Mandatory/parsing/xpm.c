/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:32:27 by abablil           #+#    #+#             */
/*   Updated: 2024/06/06 13:56:35 by abablil          ###   ########.fr       */
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

void	get_xpms(t_data *data)
{
	data->north_texture_struct = init_texture(data);
	set_texture(data, data->north_texture, data->north_texture_struct);
	data->south_texture_struct = init_texture(data);
	set_texture(data, data->south_texture, data->south_texture_struct);
	data->west_texture_struct = init_texture(data);
	set_texture(data, data->west_texture, data->west_texture_struct);
	data->east_texture_struct = init_texture(data);
	set_texture(data, data->east_texture, data->east_texture_struct);
}
