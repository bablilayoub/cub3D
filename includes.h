/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:01:40 by abablil           #+#    #+#             */
/*   Updated: 2024/05/24 18:45:39 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
typedef struct s_data
{
	char	*temp;
	char	*map_file;
	char	**map;
	int		start_point;
	size_t	biggest_line;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceiling_color;
}	t_data;

#endif