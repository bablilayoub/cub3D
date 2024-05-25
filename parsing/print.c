/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:21:54 by abablil           #+#    #+#             */
/*   Updated: 2024/05/23 21:22:01 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_textures(t_data *data)
{
	printf("North texture: |%s|\n", data->north_texture);
	printf("South texture: |%s|\n", data->south_texture);
	printf("West texture: |%s|\n", data->west_texture);
	printf("East texture: |%s|\n", data->east_texture);
	printf("\n");
}

void	print_colors(t_data *data)
{
	printf("Floor color: |%s|\n", data->floor_color);
	printf("Ceiling color: |%s|\n", data->ceiling_color);
	printf("\n");
}