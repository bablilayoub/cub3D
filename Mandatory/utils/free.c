/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:08:27 by abablil           #+#    #+#             */
/*   Updated: 2024/06/04 22:53:39 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../../cub3D.h"

void	destory_texture(t_data *data, t_texture *texture)
{
	if (!texture)
		return ;
	if (texture && texture->img && data->mlx)
		mlx_destroy_image(data->mlx, texture->img);
	free(texture);
}

void	more_free(t_data *data)
{
	destory_texture(data, data->north_texture_struct);
	destory_texture(data, data->south_texture_struct);
	destory_texture(data, data->west_texture_struct);
	destory_texture(data, data->east_texture_struct);
	if (data->floor_color_rgb)
		free(data->floor_color_rgb);
	if (data->ceiling_color_rgb)
		free(data->ceiling_color_rgb);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
}

void	free_data(t_data *data)
{
	if (data->temp)
		free(data->temp);
	if (data->map_file)
		free(data->map_file);
	if (data->north_texture)
		free(data->north_texture);
	if (data->south_texture)
		free(data->south_texture);
	if (data->west_texture)
		free(data->west_texture);
	if (data->east_texture)
		free(data->east_texture);
	if (data->floor_color)
		free(data->floor_color);
	if (data->ceiling_color)
		free(data->ceiling_color);
	if (data->map)
		free_array(data->map);
	if (data->player)
		free(data->player);
	if (data->rays)
		free(data->rays);
	more_free(data);
}

void	free_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
