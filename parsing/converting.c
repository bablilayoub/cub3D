/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:32:27 by abablil           #+#    #+#             */
/*   Updated: 2024/05/30 16:39:29 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Get texture from the walls
void	get_texture(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx, data->north_texture, &data->texture[0].width, &data->texture[0].height);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx, data->south_texture, &data->texture[1].width, &data->texture[1].height);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx, data->west_texture, &data->texture[2].width, &data->texture[2].height);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx, data->east_texture, &data->texture[3].width, &data->texture[3].height);
	if (!data->texture[0].img || !data->texture[1].img || !data->texture[2].img || !data->texture[3].img || !data->texture[4].img)
		exit_game("Error\nTexture not found", data, -1, 0);
	data->texture[0].addr = mlx_get_data_addr(data->texture[0].img, &data->texture[0].bits_per_pixel, &data->texture[0].line_length, &data->texture[0].endian);
	data->texture[1].addr = mlx_get_data_addr(data->texture[1].img, &data->texture[1].bits_per_pixel, &data->texture[1].line_length, &data->texture[1].endian);
	data->texture[2].addr = mlx_get_data_addr(data->texture[2].img, &data->texture[2].bits_per_pixel, &data->texture[2].line_length, &data->texture[2].endian);
	data->texture[3].addr = mlx_get_data_addr(data->texture[3].img, &data->texture[3].bits_per_pixel, &data->texture[3].line_length, &data->texture[3].endian);
}
